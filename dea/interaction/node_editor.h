#pragma once

#include "node.h"
#include "node/frame.h"
#include "mouse_interaction.h"
#include "selection.h"

namespace dea::interaction {

class NodeEditor {
public:
	NodeEditor(node::Node* node, Frame* parent) : node_(node) {
		frame_.setName("nodeEditor");
		frame_.disable();
		node::Container::append(&frame_, parent);
	};

	virtual ~NodeEditor() {
		if (auto* parent = frame_.getParent()) {
			node::Container::remove(&frame_, parent);
		}
	};

	virtual void update() {
		if (!node_) return;

		frame_.setTransform(GetWorldMatrix(node_));
		frame_.setSize(getSize(node_));
	}
	
	void update(const node::Matrix& transform, const node::Vector& size) {
		frame_.setTransform(transform);
		frame_.setSize(size);
	}

	void selectNearestCtrlNode(node::Vector worldPoint, std::function<bool(node::NodeConstPtr)> filter);

	void setEditNode(node::NodePtr node) { node_ = node; }
	auto* getEditNode() { return node_; }

	auto* getContainer() { return &frame_; }

	template<typename T>
	T* as() {
		return dynamic_cast<T*>(this);
	}

protected:
	node::Node* node_;
	Frame frame_;
};

} // namespace dea::interaction