#include "document.h"
#include "dezaina.h"
#include "node.h"
#include "base/data.h"
#include "node.h"
#include "resource.h"
#include "spdlog/spdlog.h"

namespace dea::document {

using namespace node;

Document::Document(uint32_t sessionId) : sessionId_(sessionId) {}

void Document::dump() {
	NodeIter iter(root_);
	while (iter.isValid()) {
		auto* node = iter.get();
		++iter;
	}
}

void Document::dump(node::Node* node) const {
  NodeIter iter(node);
  while (iter.isValid()) {
    auto *node = iter.get();
    spdlog::info("{}", getNodeTypeString(node));
    ++iter;
  }
}

bool Document::applyMessage(kiwi::ByteBuffer& buffer, const message::BinarySchema* schema) {
	message::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool, schema);
	if (!decode_success) {
		return false;
	}
	applyMessage(message);
	return true;
}

bool Document::processBlobMessage(kiwi::Array<message::Blob> &blobs) {
  uint32_t index = 0;
  for (const auto &blob : blobs) {
    auto *bytes = blob.bytes();
    auto &&data = base::Data::MakeWithCopy(bytes->data(), bytes->size());
    auto *resourceItem = resource::BlobResource::add(std::move(data));
    if (resourceItem) {
      blobIdMap_[index++] = resourceItem->id();
    }
  }
  return true;
}

bool Document::applyMessage(message::Message& message) {
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
					node = createNode<DocumentNode>(id, false);
					break;
				case NodeType::CANVAS:
					node = createNode<PageNode>(id, false);
					break;
				case NodeType::FRAME:
					node = createNode<FrameNode>(id, false);
					break;
				case NodeType::RECTANGLE:
				case NodeType::ROUNDED_RECTANGLE:
					node = createNode<RectangleNode>(id, false);
					break;
				case NodeType::VECTOR:
					node = createNode<VectorNode>(id, false);
					break;
				case NodeType::STAR:
					node = createNode<StarNode>(id, false);
					break;
				case NodeType::LINE:
					node = createNode<LineNode>(id, false);
					break;
				case NodeType::ELLIPSE:
					node = createNode<EllipseNode>(id, false);
					break;
				case NodeType::REGULAR_POLYGON:
					node = createNode<PolygonNode>(id, false);
					break;
				case NodeType::TEXT:
					node = createNode<TextNode>(id, false);
					break;
				case NodeType::SYMBOL:
					node = createNode<SymbolNode>(id, false);
					break;
				case NodeType::INSTANCE:
					node = createNode<InstanceNode>(id, false);
					break;
				default:
					assert(false);
					break;
			}
		}

    if (node_change.fillGeometry()) {
      for (auto &fillGeometry : *node_change.fillGeometry()) {
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
	if (auto* documentNode = node_cast<DocumentNode>(child)) {
		root_ = documentNode;
		return;
	}

  auto *parent = getParent(child);
  assert(parent);
  append(child, parent);
}

void Document::append(node::Node *child, node::Node *parent) {
  if (!node::Container::append(child, parent)) {
    return;
  }

  if (child->getParentIndex().guid != parent->getGuid()) {
    auto parentIndex = child->getParentIndex();
    parentIndex.guid = parent->getGuid();
    child->setParentIndex(parentIndex);
    editor_.setParent(child);
  }
}

void Document::applyNodeChange(message::NodeChange *change) {
  auto *guid = change->guid();
  auto *node = getNodeById({*guid->sessionID(), *guid->localID()});
  if (!node) {
    return;
  }
  node->applyChange(*change);
}

void Document::setCurrentPage(node::PageNode *page) {
  currentPage_ = page;
  event::Event event;
  event.type = event::EventType::PageChange;
	Dezaina::instance().dispatchEvent(event);
}

node::Node *Document::getNodeById(const node::GUID &id) const {
  auto iter = nodeMap_.find(id);
  if (iter == nodeMap_.end()) {
    return nullptr;
  }
  return iter->second;
}

void Document::handleViewMatrixChange(const node::Matrix &matrix) {
  if (currentPage_) {
    currentPage_->setTransform(matrix);
  }
}

void Document::loadEmpty() {
	assert(!root_);
	root_ = createNode<DocumentNode>(node::GUID{0, 0}, false);

  auto *page = createNode<PageNode>(root_);
  setCurrentPage(page);
}

} // namespace dea::document
