#pragma once
#include "document/src/executor.h"
#include "node/include/node.h"
#include "vendor/figma/kiwi.h"
#include "editor.h"
#include <unordered_map>

namespace dea::document {

using NodeMap = std::unordered_map<node::GUID, node::Node*>;

class Document {
public:
	Document() : change_(*this) {
	}

	template<typename T>
	T* createNode(const node::GUID& id) {
	};

	template<typename T>
	T* createNode() {
	};

	void load(char* data, size_t size) {
		kiwi::ByteBuffer buffer(reinterpret_cast<uint8_t*>(data), size);
		change_.applyMessage(buffer);
	}
	void unload() {
	}

	void append(node::Node* child) {
		if (child.type == node::NodeType::DOCUMENT) {
			root_ = child;
			return;
		}
		auto* parent = child->getParent();
		append(parent, child);
	}

	void append(node::Node* parent, node::Node* child) {
		Container::append(parent, child);
	}

	void remove(node::Node* node) {
	}

	void setRoot(node::DocumentNode* root) {
		root_ = root;
	}

	node::DocumentNode* getRoot() {
		return root_;
	}

	Node* getNodeParent(node::Node* node) {
		auto id = node->getParent();
		return getNodeById(id);
	}

	node::Node* getNodeById(const node::GUID& id) const {
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

private:
	NodeMap nodeMap_;
	change::Change change_;
  node::DocumentNode* root_;
	Editor editor_;
};

} // namespace dea::document