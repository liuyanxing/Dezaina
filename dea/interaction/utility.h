#pragma once

#include "node.h"
#include "node/rectangle.h"
#include "node/type.h"

namespace dea::interaction {

void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const node::Rect& frame);
std::vector<node::Node*> getNodesUnderCursor();
class Iter : public node::NodeIter {
public:
	Iter(node::Node* node) :
	NodeIter(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent();}) {}
};

class IterWithWorldMatrix : public node::NodeIterWithWorldMatrix {
public:
	IterWithWorldMatrix(node::Node* node) : node::NodeIterWithWorldMatrix(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent(); }) {
	}
};

}