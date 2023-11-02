#include "create_system.h"
#include "change/change_type.h"
#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "desaina.h"
#include "action_system/action_system.h"
#include "util/skia.h"
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
  if (event->dragDistanceX >= 10 || event->dragDistanceY >= 10) {
    auto* hoverNode = desaina_->document.getHoverNode();
    if (!hoverNode) {
      hoverNode = desaina_->document.getCurrentPage();
    }
    ParentIndex parentIndex;
    parentIndex.guid = hoverNode->get_guid();
    parentIndex.position = "";
    creating_node_->set_parentIndex(parentIndex);
    auto* defaultShapNode = static_cast<DefaultShapeNode*>(creating_node_);
    defaultShapNode->set_size({100, 100});
    SkMatrix matrix;
    matrix.setTranslate(100, 100);
    defaultShapNode->set_transform(util::toMatrix(matrix));
    SolidPaint paint;
    paint.set_color({1, 0, 0, 1});
    IVector<PaintUnion> paints = { {paint}};
    defaultShapNode->set_fillPaints(paints);
    desaina_->actionSystem->createNode(creating_node_, nullptr);
    creating_node_ = nullptr;
  }
}