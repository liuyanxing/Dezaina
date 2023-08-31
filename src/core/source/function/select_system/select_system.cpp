#include "select_system.h"
#include "base_type.h"
#include "desaina.h"
#include "select_system/selection.h"
#include <iostream>

void SelectSystem::buildEvents() {
  addEventListener(EventType::kMouseMove, [this](Event* event) {
    hover_nodes_.clear();
    auto mouseEvent = static_cast<MouseEvent*>(event);
    if (auto* curPage = desaina_->document.getCurrentPage()) {
      curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, hover_nodes_);
    }
  });
}

vector<Node*> SelectSystem::getHoverNodes() const {
  return hover_nodes_;
}

