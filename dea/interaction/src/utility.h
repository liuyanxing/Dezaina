#pragma once

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"
#include "node.h"
#include "node/rectangle.h"
#include "geometry/geometry.h"

namespace dea::interaction {

std::vector<node::Node*> getNodesUnderCursor();
bool isCursorOnNodePixel(float x, float y, node::NodePtr node, bool isInterNode);
SkColor readColorAtPointOfNode(float x, float y, const geometry::GeometryType& geometry, node::NodeConstPtr node, const std::vector<SkPaint>& paints);
void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame);

}