#include "create_system.h"
#include "include/core/SkPoint.h"
#include "desaina.h"
#include "action_system/action_system.h"
#include <iostream>

void CreateSystem::init() {
  bindEvents();
}

void CreateSystem::bindEvents() {
  addEventListener(EventType::kMouseDrag, [this](Event* event) {
    if (creating_node_) {
      return;
    }
    handleMouseDrag(static_cast<MouseEvent*>(event));
  });
}

void CreateSystem::handleMouseDrag(MouseEvent* event) {
  if (event->dragDistanceX >= 10 || event->dragDistanceY >= 10) {
    auto* hoverNode = desaina_->document.getHoverNode();
    if (!hoverNode) {
      hoverNode = desaina_->document.getCurrentPage();
    }
    desaina_->actionSystem->createNode(creating_node_, hoverNode, nullptr);

  }
}