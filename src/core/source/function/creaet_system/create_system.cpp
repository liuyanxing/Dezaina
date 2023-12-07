#include "create_system.h"
#include "change/change_type.h"
#include "desaina_node.h"
#include "edit_system/edit_system.h"
#include "event_system/event.h"
#include "event_system/mouse_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "desaina.h"
#include "action_system/action_system.h"
#include "util/node_geometry.h"
#include "util/skia.h"
#include "util/node_fill.h"
#include <iostream>

void CreateSystem::init() {
  bindEvents();
}

void CreateSystem::bindEvents() {
  addEventListener(EventType::kMouseDrag, [this](Event* event) {
    if (creating_node_ == nullptr) {
      return;
    }
    handleMouseDrag(static_cast<MouseEvent*>(event));
  });
}

void CreateSystem::handleMouseDrag(MouseEvent* event) {
  if (!creating_node_) {
    return;
  }
  auto dragDistanceX = event->dragDistanceX;
  auto dragDistanceY = event->dragDistanceY;
  if (dragDistanceX >= 10 || dragDistanceY >= 10) {
    auto* hoverNode = desaina_->document.getHoverNode();
    auto localX = event->localX - dragDistanceX;
    auto localY = event->localY - dragDistanceY;
    if (!hoverNode) {
      hoverNode = desaina_->document.getCurrentPage();
      localX = event->x - dragDistanceX;
      localY = event->y - dragDistanceY;
    }
    ParentIndex parentIndex;
    parentIndex.guid = hoverNode->get_guid();
    parentIndex.position = "";
    creating_node_->set_parentIndex(parentIndex);
    SolidPaint paint;
    node::setFillPaints(creating_node_, {{node::MakeSolidPaint(1, 0, 0, 1)}});
    util::setSize(creating_node_, {dragDistanceX, dragDistanceY});
    util::setTransform(creating_node_, {1, 0, localX, 0, 1, localY});
    desaina_->actionSystem->createNode(creating_node_, nullptr);
    auto id = creating_node_->get_guid();
    auto e = *event;
    desaina_->nextTick([this, id, e]() {
      desaina_->selectSystem->setSelectionByIds({id});
      desaina_->editSystem->selectCtrlNodeByPoint({e.x, e.y});
    });
    creating_node_ = nullptr;
  }
}

