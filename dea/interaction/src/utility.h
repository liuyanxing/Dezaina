#pragma once

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"
#include "node.h"
#include "node/rectangle.h"

namespace dea::interaction {

std::vector<node::Node*> getNodesUnderCursor();
bool isCursorOnNodePixel(float x, float y, node::Node* node);
SkColor readColorAtPointOfNode(float x, float y, const node::Node* node, const std::vector<SkPaint>& paints);
void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame);

}