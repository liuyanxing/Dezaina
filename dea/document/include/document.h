#pragma once
#include "../src/executor.h"
#include "node/include/node.h"
#include "node/src/page.h"
#include "vendor/figma/kiwi.h"
#include "editor.h"
#include <cstdint>
#include <iostream>
#include <unordered_map>

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
		append(getNodeParent(child), child);
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

  void setCurrentPage(node::PageNode* page) {
    currentPage_ = page;
  }
  auto* currentPage() const { return currentPage_; }

	node::DocumentNode* getRoot() {
		return root_;
	}

	node::Node* getNodeParent(node::Node* node) {
		return getNodeById(node->getParentIndex().guid);
	}

	node::Node* getNodeById(const node::GUID& id) const {
		auto iter = nodeMap_.find(id);
		if (iter == nodeMap_.end()) {
			return nullptr;
		}
		return iter->second;
	}

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
    End,
  };

	Iter(node::Node* node) : node_(node) {}
	IterDirection operator++();
	bool isValid() { return node_ != nullptr; }
	auto* get() { return node_; }
private:
	node::Node* node_;
  static inline Document* doc_ = nullptr;
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