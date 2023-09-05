#include "kiwi.h"
#include <cstring>
#include <memory>
#include <stdint.h>
#include <iostream>

#include "base_type.h"

#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "event_system/event.h"
#include <cstdint>
#include "desaina_node.h"
#include "util/node_geometry.h"
#include "desaina.h"

static Buffer decodeBlob(const Desaina_Kiwi::Blob& blob) {
  auto const data_ptr = blob.bytes();
  return Buffer::MakeWithCopy(data_ptr->data(), data_ptr->size());
}

bool Desaina::processMessage(kiwi::ByteBuffer& buffer) {
	Desaina_Kiwi::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
	if (!decode_success) {
		return false;
	}
	processMessage(message);
	return true;
}

static vector<Node*> messageNodes;

bool Desaina::processMessage(const Desaina_Kiwi::Message& message) {
	auto type = message.type();
	if (type == nullptr) {
		return false;
	}
	blob_id_remap_.clear();
	messageNodes.clear();
	
	if (auto* blobPtr = message.blobs()) {
    auto& blobs = *blobPtr;
    int index = 0;
    for (auto& blob : blobs) {
    	if (!document.isLoaded()) {
    		// todo add blob without query;
    	};
    	auto geometry = addGeomtryFromBlob(decodeBlob(blob));
    	blob_id_remap_[index++] = geometry.first;
    }
  }
  
	using Desaina_Kiwi::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			applyNodeChanges(message);
			break;
		default:
			break;
	}
	
	if (document.isLoaded()) {
		remapBlobId();
	}
	
	return true;
}

void Desaina::applyNodeChanges(const Desaina_Kiwi::Message& message) {
	auto* node_changs = message.nodeChanges();
	for (const auto& node_change : *node_changs) {
		applyNodeChange(node_change);
	}
}

void Desaina::remapBlobId() {
	for (auto& node : messageNodes) {
		auto& fillGeometry = util::getFillGeometry(node);
		for (auto& geometry : fillGeometry) {
		  const_cast<Path&>(geometry).commandsBlob = blob_id_remap_[geometry.commandsBlob];
		}
	}
}

void Desaina::applyNodeChange(const Desaina_Kiwi::NodeChange& node_change) {
	GUID id;
	auto* guid = node_change.guid();
	id.applyChange(*guid);
	auto node_or_null = document.getNodeById(id);
	Node* node = nullptr;
	if (!node_or_null.has_value()) {
		auto type = *node_change.type();
		using Desaina_Kiwi::NodeType;
		switch (type) {
			case NodeType::DOCUMENT:
				node = &document;
				break;
			case NodeType::CANVAS:
				node = document.createNode<PageNode>(id);
				break;
			case NodeType::FRAME:
				node = document.createNode<FrameNode>(id);
				break;
			case NodeType::RECTANGLE:
      case NodeType::ROUNDED_RECTANGLE:
				node = document.createNode<RectangleNode>(id);
				break;
      case NodeType::VECTOR:
        node = document.createNode<VectorNode>(id);
      case NodeType::STAR:
				node = document.createNode<StarNode>(id);
				break;
			case NodeType::LINE:
				node = document.createNode<LineNode>(id);
				break;
			case NodeType::ELLIPSE:
				node = document.createNode<EllipseNode>(id);
				break;
			case NodeType::REGULAR_POLYGON:
				node = document.createNode<PolygonNode>(id);
				break;
      case NodeType::TEXT:
        node = document.createNode<TextNode>(id);
        break;
			default:
				assert(false);
				break;
		}
		document.addNodeToMap(node);
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
	messageNodes.push_back(node);
}

bool Desaina::encode(kiwi::ByteBuffer &buffer) {
	kiwi::MemoryPool pool;
	Desaina_Kiwi::Message message;
	message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
	auto allNodes = document.getAllNodes();
	auto& nodeChanges = message.set_nodeChanges(pool, allNodes.size());

	for (uint32_t i = 0; i < allNodes.size(); ++i) {
		auto& nodeChange = nodeChanges[i];
		allNodes[i]->toChange(nodeChange, pool);
	}

	return message.encode(buffer);
}

void Desaina::buildEvents() {
  viewPortSystem.addEventListener(EventType::kViewPortChange, [this](Event* event) {
    if (auto* curPage = document.getCurrentPage()) {
      curPage->setViewMatrix(viewPortSystem.getViewMatrix());
    }
  });
}

void Desaina::addSystems() {
	systems_.push_back(&eventSystem);
  systems_.push_back(&viewPortSystem);
  systems_.push_back(&editSystem);
  systems_.push_back(&selectSystem);
  systems_.push_back(&actionSystem);
  systems_.push_back(&changeSystem);
  systems_.push_back(&renderSystem);
}

void Desaina::tick() {
  for (const auto &system : systems_) {
    system->tick();
  }
}
