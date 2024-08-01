#pragma once

#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"
#include "interaction/node/rectangle.h"

namespace dea::interaction {

vector<Node*> getNodesUnderCursor();
bool isCursorOnNodePixel(float x, float y, const Node* node);
SkColor readColorAtPointOfNode(float x, float y, const Node* node, const vector<SkPaint>& paints);
void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame);

}