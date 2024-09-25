#pragma once

#include "node.h"
#include "node/frame.h"
#include "mouse_interaction.h"
#include "selection.h"

namespace dea::interaction {

class NodeEditor {
public:
	NodeEditor(node::Node& node) : node_(node) {};
	virtual void update() = 0;
	void selectNearestCtrlNode(node::Vector worldPoint, std::function<bool(node::NodeConstPtr)> filter);
	auto* getContainer() { return &frame_; }
	void onEvent(event::Event& event) { mouseInteraction_.onEvent(event); }

protected:
	node::Node& node_;
	Frame frame_;
	Selection selection_{&frame_, [](node::Vector size){ return size; }};
	MouseInteraction mouseInteraction_{selection_};
};

} // namespace dea::interaction