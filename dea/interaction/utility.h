#pragma once

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"
#include "node.h"
#include "node/rectangle.h"
#include "geometry/geometry.h"
#include "node/type.h"

namespace dea::interaction {

std::vector<node::Node*> getNodesUnderCursor();
bool isCursorOnNodePixel(float x, float y, node::NodePtr node, bool isInterNode);
SkColor readColorAtPointOfNode(float x, float y, const geometry::GeometryType& geometry, node::NodeConstPtr node, const std::vector<SkPaint>& paints);
void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame);

class Iter : public utility::NodeIter {
public:
	Iter(node::Node* node) :
	NodeIter(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent();}) {}
};

class IterWithWorldMatrix : public utility::NodeIterWithWorldMatrix {
public:
	IterWithWorldMatrix(node::Node* node) : utility::NodeIterWithWorldMatrix(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent(); }) {
	}
};

}