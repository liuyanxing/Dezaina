#include "select_system.h"
#include "base_type.h"
#include "desaina.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "select_system/selection.h"
#include <iostream>

void SelectSystem::buildEvents() {
  addEventListener(EventType::kMouseMove, [this](Event* event) {
    hover_node_ = nullptr;
    vector<Node*> nodes;
    auto mouseEvent = static_cast<MouseEvent*>(event);
    if (auto* curPage = desaina_->document.getCurrentPage()) {
      curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, nodes);
      SkPaint paint;
      paint.setColor(SK_ColorWHITE);
      for (auto& node : nodes) {
        if (desaina_->renderSystem.readColorAtPointOfNode(node, mouseEvent->x, mouseEvent->y, {paint}) != 0) {
          hover_node_ = node;
          break;
        }
      }
    }
  });
}

Node* SelectSystem::getHoverNode() const {
  return hover_node_;
}

