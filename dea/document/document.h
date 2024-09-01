#pragma once
#include "include/core/SkRect.h"
#include "include/core/SkPoint.h"
#include "vendor/figma/kiwi.h"
#include "editor.h"
#include <cstdint>
#include "utility/node_utility.h"
#include "event.h"
#include "node.h"

namespace dea::document {

using NodeMap = std::unordered_map<node::GUID, node::Node*>;
using SkBound = SkRect;

class Document : public event::EventEmitter{
public:
	Document(uint32_t sessionId);

	template<typename T>
	T* createNode(const node::GUID& id) {
		auto* node = new T();
		node->setGuid(id);
		nodeMap_[id] = node;
		return node;
	};

	template<typename T>
	T* createNode() { return createNode<T>(node::GUID{sessionId_, localId_++}); };

	bool load(char* data, size_t size) {
		kiwi::ByteBuffer buffer(reinterpret_cast<uint8_t*>(data), size);
	  auto res = applyMessage(buffer);
    if (!root_->empty()) {
      setCurrentPage(static_cast<node::PageNode*>(root_->firstChild()));
    }
    return res;
	}

	void unload() {}

	void append(node::Node* child);
	void append(node::Node* parent, node::Node* child);
	void updateNode(message::NodeChange* change);
	void remove(node::Node* node) { }

	void setRoot(node::DocumentNode* root) { root_ = root; }
	auto* root() const { return root_; }
  bool loaded() const { return root_ != nullptr; }

  auto* currentPage() const { return currentPage_; }
	node::DocumentNode* getRoot() { return root_; }
	node::Node* getParent(node::Node* node) { return getNodeById(node->getParentIndex().guid); }

  std::vector<node::Node*> getNodes(float x, float y);
  std::vector<node::Node*> getNodesWithRadius(const SkPoint& point, float radius);

  void setCurrentPage(node::PageNode* page);
	node::Node* getNodeById(const node::GUID& id) const;
  void handleViewMatrixChange(const node::Matrix& matrix);
	void flushEditor();

	auto& editor() { return editor_; }

	bool applyMessage(kiwi::ByteBuffer& buffer);
	bool processMessage(message::Message& message);
	bool processBlobMessage(kiwi::Array<message::Blob>& blobs);
	bool processNodeChanges(message::Message& message);

	void dump();
	void dump(node::Node* node) const;

class Iter : public utility::NodeIter {
public:
	Iter(node::Node* node) : utility::NodeIter(node, [this](node::Node* node) { return doc_->getParent(node); }) {
  }
  static inline Document* doc_ = nullptr;
};

class IterWithWorldMatrix : public utility::NodeIterWithWorldMatrix {
public:
	IterWithWorldMatrix(node::Node* node) : utility::NodeIterWithWorldMatrix(node, [](node::Node* node) { return Iter::doc_->getParent(node); }) {
  }
};

private:
	NodeMap nodeMap_{100};
  node::DocumentNode* root_;
  node::PageNode* currentPage_;
	Editor editor_;
	uint32_t sessionId_;
	uint32_t localId_{0};
	std::unordered_map<uint32_t, uint32_t> blobIdMap_{};
};

} // namespace dea::document