#include "selection.h"
#include "interaction.h"
#include "desaina.h"

namespace dea::interaction {

void Selection::onMouseMove(MouseEvent* event) {
  vector<Node*> nodes;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto* desaina = interaction_->dezaina();
  auto& nodeUtil = desaina->nodeUtil;
  if (auto* curPage = desaina->document.getCurrentPage()) {
    curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, nodes);
    for (auto& node : nodes) {
      if (isCursorOnNodePixel(mouseEvent->x, mouseEvent->y, node)) {
        if (node != hoverNode_) {
          event->target = node;
        }
        hoverNode_ = node;
        auto matrix = document::getWorldMatrix(node);
        auto point = utility::mapPointToLocal(matrix, {mouseEvent->x, mouseEvent->y});
        mouseEvent->localX = point.x();
        mouseEvent->localY = point.y();
        break;
      }
    }
    if (nodes.empty()) {
      mouseEvent->localX = mouseEvent->x;
      mouseEvent->localY = mouseEvent->y;
    }
  }
}

void Selection::onMouseDown(MouseEvent* event) {
  if (hoverNode_ != nullptr) {
    setSelection({hoverNode_});
  } else {
    setSelection(vector<Node*>{});
  }
}

void Selection::setSelection(const vector<Node*>& nodes) {
  if (!nodes.empty()) {
    hoverNode_ = nullptr;
  } 
  selection_ = nodes;
}

void Selection::setSelection(const vector<GUID>& nodesIds) {

}

}
