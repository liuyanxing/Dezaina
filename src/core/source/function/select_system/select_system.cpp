#include "select_system.h"
#include "base/math.h"
#include "base_type.h"
#include "desaina.h"
#include "event_system/ui_event.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "select_system/selection.h"
#include "render_system/render_system.h"
#include "util/node_geometry.h"
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
  desaina_->document.setHoverNode(nullptr);
  vector<Node*> nodes;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  if (auto* curPage = desaina_->document.getCurrentPage()) {
    curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, nodes);
    SkPaint paint;
    paint.setColor(SK_ColorWHITE);
    for (auto& node : nodes) {
      if (desaina_->renderSystem->readColorAtPointOfNode(node, mouseEvent->x, mouseEvent->y, {paint}) != 0) {
        desaina_->document.setHoverNode(node);
        auto matrix = util::getWorldMatrix(node, &desaina_->document);
        auto point = base::mapPointToLocal({mouseEvent->x, mouseEvent->y}, matrix);
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

void SelectSystem::handleMouseDown(Event* event) {
  if (desaina_->document.getHoverNode() != nullptr) {
    setSelection({desaina_->document.getHoverNode()});
  } else {
    setSelection({});
  }
}

void SelectSystem::setSelection(const vector<Node*>& nodes) {
  desaina_->document.setSelectedNodes(nodes);
  UIEvent event;
  event.type = EventType::kSelectionChange;
  emit(event);
}

void SelectSystem::setSelectionByIds(const vector<GUID>& nodesIds) {
  desaina_->document.setSelectedNodeByIds(nodesIds);
  UIEvent event;
  event.type = EventType::kSelectionChange;
  emit(event);
}

