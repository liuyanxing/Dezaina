#pragma once
#include "executor.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/include/node.h"
#include "node/src/node-base/node.h"
#include "node/src/page.h"
#include "vendor/figma/kiwi.h"
#include "editor.h"
#include <array>
#include <cstdint>
#include <unordered_map>
#include "common/array.h"

namespace dea::document {

using NodeMap = std::unordered_map<node::GUID, node::Node*>;

class Document {
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
	T* createNode() {
		return createNode<T>(node::GUID{sessionId_, localId_++});
	};

	bool load(char* data, size_t size) {
		kiwi::ByteBuffer buffer(reinterpret_cast<uint8_t*>(data), size);
	  auto res = change_.applyMessage(buffer);
    if (!root_->empty()) {
      setCurrentPage(static_cast<node::PageNode*>(root_->firstChild()));
    }
    return res;
	}

	void unload() {
	}

	void append(node::Node* child) {
		auto* root = node::node_cast<node::DocumentNode*>(child);
		if (root) {
			root_ = root;
			return;
		}

		append(getParent(child), child);
	}

	void append(node::Node* parent, node::Node* child) {
		if (!parent) {
			return;
		}
		node::Container::append(parent, child);
	}

	void remove(node::Node* node) {
	}

	void setRoot(node::DocumentNode* root) {
		root_ = root;
	}
	auto* root() const { return root_; }

  bool loaded() const {
    return root_ != nullptr;
  }

  void setCurrentPage(node::PageNode* page) {
    currentPage_ = page;
  }
  auto* currentPage() const { return currentPage_; }

	node::DocumentNode* getRoot() {
		return root_;
	}

	node::Node* getParent(node::Node* node) {
		return getNodeById(node->getParentIndex().guid);
	}

	node::Node* getNodeById(const node::GUID& id) const {
		auto iter = nodeMap_.find(id);
		if (iter == nodeMap_.end()) {
			return nullptr;
		}
		return iter->second;
	}

  SkMatrix getWorldMatrix(node::Node* node);

  std::vector<node::Node*> getNodes(float x, float y);
  std::vector<node::Node*> getNodesWithRadius(const SkPoint& point, float radius);

	void flushEditor() {
		if (editor_.empty()) {
			return;
		}

		Executor executor(*this, editor_, change_);
		executor.execute();
	}

	auto& editor() {
		return editor_;
	}

	void dump();

class Iter {
friend class Document;
public:
  enum IterDirection {
    Forward,
    Backword,
    Right,
    End,
  };

	Iter(node::Node* node);
	IterDirection operator++();
	IterDirection operator--();
	bool isValid() { return node_ != nullptr; }
	auto* get() { return node_; }
  auto& getWorldMatrix() { return world_; }
private:
	node::Node* node_;
	node::Node* root_;
  SkMatrix world_;
  base::array<SkMatrix, 16> wordStack_;
  static inline Document* doc_ = nullptr;
  bool setNode(node::Node* node, IterDirection direction);
};

private:
	NodeMap nodeMap_{100};
	Change change_;
  node::DocumentNode* root_;
  node::PageNode* currentPage_;
	Editor editor_;
	uint32_t sessionId_;
	uint32_t localId_{0};
};

} // namespace dea::document