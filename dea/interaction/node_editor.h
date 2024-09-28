#pragma once

#include "node.h"
#include "node/frame.h"
#include "mouse_interaction.h"
#include "selection.h"

namespace dea::interaction {

class NodeEditor {
public:
	NodeEditor(node::Node& node, node::Node& parent) : node_(node) {
		frame_.setName("nodeEditor");
		node::Container::append(&frame_, &parent);
	};
	virtual void update() = 0;
	void selectNearestCtrlNode(node::Vector worldPoint, std::function<bool(node::NodeConstPtr)> filter);
	auto* getContainer() { return &frame_; }
	auto* getEditNode() { return &node_; }

protected:
	node::Node& node_;
	Frame frame_;
};

} // namespace dea::interaction