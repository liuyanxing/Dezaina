#include "select_system.h"
#include "base_type.h"
#include "desaina.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "select_system/selection.h"
#include <iostream>

void SelectSystem::buildEvents() {
  addEventListener(EventType::kMouseMove, [this](Event* event) {
    handleMouseMove(event);
  });
  
  addEventListener(EventType::kMouseDown, [this](Event* event) {
    handleMouseDown(event);
  });
}

void SelectSystem::handleMouseMove(Event* event) {
  hovered_node_id_ = std::nullopt;
  vector<Node*> nodes;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  if (auto* curPage = desaina_->document.getCurrentPage()) {
    curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, nodes);
    SkPaint paint;
    paint.setColor(SK_ColorWHITE);
    for (auto& node : nodes) {
      if (desaina_->renderSystem.readColorAtPointOfNode(node, mouseEvent->x, mouseEvent->y, {paint}) != 0) {
        hovered_node_id_ = node->get_guid();
        break;
      }
    }
  }
}

void SelectSystem::handleMouseDown(Event* event) {
  if (hovered_node_id_.has_value()) {
    selected_node_id_.push_back(hovered_node_id_.value());
  }
}

Node* SelectSystem::getHoverNode() const {
  if (!hovered_node_id_.has_value()) {
    return nullptr;
  }
  auto node = desaina_->document.getNodeById(hovered_node_id_.value());
  if (node.has_value()) {
    return node.value();}
  return nullptr;
}

vector<Node*> SelectSystem::getSelectedNodes() const {
  vector<Node*> nodes;
  for (auto& id : selected_node_id_) {
    auto node = desaina_->document.getNodeById(id);
    if (node.has_value()) {
      nodes.push_back(node.value());
    }
  }
  return nodes;
}

