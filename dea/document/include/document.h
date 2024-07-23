#pragma once
#include "../src/executor.h"
#include "node/include/node.h"
#include "vendor/figma/kiwi.h"
#include "editor.h"
#include <cstdint>
#include <unordered_map>

namespace dea::document {

using NodeMap = std::unordered_map<node::GUID, node::Node*>;

class Document {
public:
	Document(uint32_t sessionId) : sessionId_(sessionId), change_(*this) {
	}

	template<typename T>
	T* createNode(const node::GUID& id) {
		auto* node = new T();
		node->setGuid(id);
		return node;
	};

	template<typename T>
	T* createNode() {
		return createNode<T>(node::GUID{sessionId_, localId_++});
	};

	bool load(char* data, size_t size) {
		kiwi::ByteBuffer buffer(reinterpret_cast<uint8_t*>(data), size);
	  return change_.applyMessage(buffer);
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
		node::Container::append(parent, child);
	}

	void remove(node::Node* node) {
	}

	void setRoot(node::DocumentNode* root) {
		root_ = root;
	}

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

class Iter {
public:
	Iter(node::Node* node) : node_(node) {
	}
  
private:
	node::Node* node_;
};

private:
	NodeMap nodeMap_;
	Change change_;
  node::DocumentNode* root_;
	Editor editor_;
	uint32_t sessionId_;
	uint32_t localId_;
};

} // namespace dea::document