#include "rectangle_editor.h"
#include "node.h"

namespace dea::interaction {

using namespace node;

void RectangleEditor::update() {
	auto* node = node::node_cast<node::RectangleNode>(&node_);
	assert(node);
	NodeEditor::update();
	BoundEditor::update();
	RadiusEditor::update(
		{node->getRectangleTopLeftCornerRadius(), node->getRectangleTopRightCornerRadius(),
		 node->getRectangleBottomRightCornerRadius(), node->getRectangleBottomLeftCornerRadius()});
}

} // namespace dea::interaction