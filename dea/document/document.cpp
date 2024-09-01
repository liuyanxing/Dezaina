#include "document.h"
#include "include/core/SkRect.h"
#include "include/core/SkPoint.h"
#include "node.h"
#include "base/data.h"
#include "resource.h"
#include "utility/coords.h"
#include "spdlog/spdlog.h"

namespace dea::document {

using namespace node;

Document::Document(uint32_t sessionId) : sessionId_(sessionId) {
	Iter::doc_ = this;
}

void Document::dump() {
	Iter iter(root_);
	while (iter.isValid()) {
		auto* node = iter.get();
		++iter;
	}
}

void Document::dump(node::Node* node) const {
  Iter iter(node);
  while (iter.isValid()) {
    auto* node = iter.get();
    spdlog::info("{}", getNodeTypeString(node));
    ++iter;
  }
}

std::vector<node::Node*> Document::getNodesWithRadius(const SkPoint& point, float radius) {
  std::vector<node::Node*> nodes;
  if (!currentPage_) {
    return nodes;
  }

  IterWithWorldMatrix iter(currentPage_);
  while (iter.isValid()) {
    auto* node = iter.get();
    if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
      auto local = utility::mapPointToLocal(point, iter.getWorldMatrix());
      auto localRect = SkRect::MakeXYWH(local.x() - radius / 2, local.y() - radius / 2, radius, radius);
      auto size = shape->getSize();
      auto bound = SkRect::MakeXYWH(0, 0, size.x, size.y);
      if (bound.intersects(localRect)) {
        nodes.push_back(node);
      }
    }
    ++iter;
  }
  return nodes;
}

bool Document::applyMessage(kiwi::ByteBuffer& buffer) {
	message::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
	if (!decode_success) {
		return false;
	}
	processMessage(message);
	return true;
}

bool Document::processBlobMessage(kiwi::Array<message::Blob>& blobs) {
	uint32_t index = 0;
	for (const auto& blob : blobs) {
		auto* bytes = blob.bytes();
		auto&& data = base::Data::MakeWithCopy(bytes->data(), bytes->size());
		auto* resourceItem = resource::BlobResource::add(std::move(data));
		if (resourceItem) {
			blobIdMap_[index++] = resourceItem->id();
		}
	}
	return true;
}

bool Document::processMessage(message::Message& message) {
	auto type = message.type();
	if (type == nullptr) {
		return false;
	}

  processBlobMessage(*message.blobs());
  
	using message::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			processNodeChanges(message);
			break;
		default:
			break;
	}

	blobIdMap_.clear();
	
	return true;
}

bool Document::processNodeChanges(message::Message& message) {
	using namespace dea::node;
	auto* node_changs = message.nodeChanges();
	for (auto& node_change : *node_changs) {
		GUID id;
		auto* guid = node_change.guid();
		id.applyChange(*guid);
		auto* node = getNodeById(id);
		bool isNewNode = !node;
		if (!node) {
			auto type = *node_change.type();
			using message::NodeType;
			switch (type) {
				case NodeType::DOCUMENT:
					node = createNode<DocumentNode>();
					break;
				case NodeType::CANVAS:
					node = createNode<PageNode>(id);
					break;
				case NodeType::FRAME:
					node = createNode<FrameNode>(id);
					break;
				case NodeType::RECTANGLE:
				case NodeType::ROUNDED_RECTANGLE:
					node = createNode<RectangleNode>(id);
					break;
				case NodeType::VECTOR:
					node = createNode<VectorNode>(id);
					break;
				case NodeType::STAR:
					node = createNode<StarNode>(id);
					break;
				case NodeType::LINE:
					node = createNode<LineNode>(id);
					break;
				case NodeType::ELLIPSE:
					node = createNode<EllipseNode>(id);
					break;
				case NodeType::REGULAR_POLYGON:
					node = createNode<PolygonNode>(id);
					break;
				case NodeType::TEXT:
					node = createNode<TextNode>(id);
					break;
				case NodeType::SYMBOL:
					node = createNode<SymbolNode>(id);
					break;
				case NodeType::INSTANCE:
					node = createNode<InstanceNode>(id);
					break;
				default:
					assert(false);
					break;
			}
		}

		if (node_change.fillGeometry()) {
			for (auto& fillGeometry : *node_change.fillGeometry()) {
				fillGeometry.set_commandsBlob(blobIdMap_[*fillGeometry.commandsBlob()]);
			}
		}

		node->applyChange(node_change);
		if (isNewNode) {
			append(node);
		}
	}
	return true;

}

void Document::append(node::Node* child) {
  auto* root = node::node_cast<node::DocumentNode*>(child);
  if (root) {
    root_ = root;
    return;
  }

  append(getParent(child), child);
}

void Document::append(node::Node* parent, node::Node* child) {
  if (!parent) {
    return;
  }
  node::Container::append(parent, child);
}

void Document::updateNode(message::NodeChange* change) {
  auto* guid = change->guid();
  auto* node = getNodeById({*guid->sessionID(), *guid->localID()});
  if (!node) {
    return;
  }
  // node->update(change);
}

void Document::setCurrentPage(node::PageNode* page) {
  currentPage_ = page;
  event::Event event;
  event.type = event::EventType::PageChange;
  emit(event);
}

node::Node* Document::getNodeById(const node::GUID& id) const {
  auto iter = nodeMap_.find(id);
  if (iter == nodeMap_.end()) {
    return nullptr;
  }
  return iter->second;
}


void Document::handleViewMatrixChange(const node::Matrix& matrix) {
  if (currentPage_) {
    currentPage_->setTransform(matrix);
  }
}

}
