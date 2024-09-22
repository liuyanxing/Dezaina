#pragma once

#include "node.h"
#include "node/rectangle.h"
#include "node/type.h"

namespace dea::interaction {

void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const node::Rect& frame);
std::vector<node::Node*> getNodesUnderCursor();
void setEventLocalPosition(event::UIEvent& event, const node::NodeIterWithWorldMatrix& iter);

}