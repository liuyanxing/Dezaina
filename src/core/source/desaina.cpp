
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
#include "desaina.h"

static DataSharedPtr decodeGeometryBlob(const Desaina_Kiwi::Blob& blob) {
  auto const data_ptr = blob.bytes();
  if (data_ptr == nullptr) {
    return nullptr;
  }
  return Data::MakeWithCopy(data_ptr->data(), data_ptr->size());
}

bool Desaina::processMessage(kiwi::ByteBuffer& buffer) {
	Desaina_Kiwi::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
	if (!decode_success) {
		return false;
	}
	auto type = message.type();
	if (type == nullptr) {
		return false;
	}

	using Desaina_Kiwi::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			applyNodeChanges(message);
			break;
		default:
			break;
	}
  auto blobs = *message.blobs();
  for (auto& blob : blobs) {
    document.appendGeometryByBlob(decodeGeometryBlob(blob));
  }
	return true;
}

void Desaina::applyNodeChanges(const Desaina_Kiwi::Message& message) {
	auto* node_changs = message.nodeChanges();
	for (const auto& node_change : *node_changs) {
		applyNodeChange(node_change);
	}
}

void Desaina::applyNodeChange(const Desaina_Kiwi::NodeChange& node_change) {
	GUID id;
	auto* guid = node_change.guid();
	id.applyChange(*guid);
	auto node_or_null = document.getNodeById(id);
	Node* node;
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
			default:
				break;
		}
		document.addNodeToMap(node);
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
}

bool Desaina::encode(kiwi::ByteBuffer &buffer) {
	kiwi::MemoryPool pool;
	Desaina_Kiwi::Message message;
	message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
	auto allNodes = document.getAllNodes();
	auto& nodeChanges = message.set_nodeChanges(pool, allNodes.size());

	for (uint32_t i = 0; i < allNodes.size(); ++i) {
		auto& nodeChange = nodeChanges[i];
		allNodes[i]->encode(nodeChange, pool);
	}

	return message.encode(buffer);
}

void Desaina::buildEvents() {
}

void Desaina::addSystems() {
  auto render_system = std::make_unique<RenderSystem>(this);
  systems_.push_back(std::move(render_system));
}

void Desaina::tick() {
  for (const auto &system : systems_) {
    system->tick();
  }
}
