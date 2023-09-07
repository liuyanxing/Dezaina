#include "document.h"
#include "bound_editor.h"
#include "desaina.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "event_system/hit_tester.h"
#include "event_system/mouse_event.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include "util/node_geometry.h"
#include "util/skia.h"
#include "base/math.h"
#include <iostream>

static bool isFirstDiagonal(EditorHitNode* node) {
  return node->index % 2 == 0;
}

static bool shouldInverse(EditorHitNode* node) {
  return node->index % 3 == 0;
}

static bool inverseDelta(EditorHitNode* node, MouseEvent* event) {
  if (!shouldInverse(node)) {
    return false;
  }
  event->deltaX = -event->deltaX;
  event->deltaY = -event->deltaY;
  return true;
}

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  init();
}

void BoundEditor::init() {
  bindEvents();
  bindInteractionArea();
}

void BoundEditor::addHitNode(EditorHitNodeType type, int index, const SkRect& rect) {
  hit_nodes_.push_back(EditorHitNode::Make(type, index, rect));
  auto* hit_node = &hit_nodes_.back();
  editor_->hit_tester->insert(hit_node);
}

void BoundEditor::bindInteractionArea() {
  const auto& bound = editor_->getEditBound();
  constexpr float kCornerCtrlNodeSize = 5;
  constexpr float kEdgeCtrlNodeSize = 1;
  constexpr float kCornerCtrlNodeHalfSize = kCornerCtrlNodeSize / 2;
  constexpr float kEdgeCtrlNodeHalfSize = kEdgeCtrlNodeSize / 2;
  auto [left, top, right, bottom] = bound;
  auto width = bound.width();
  auto height = bound.height();
  auto leftTopCornerCtrlRect = SkRect::MakeXYWH(left - kCornerCtrlNodeHalfSize, top - kCornerCtrlNodeHalfSize, kCornerCtrlNodeSize, kCornerCtrlNodeSize);
  addHitNode(EditorHitNodeType::kBoundCorner, 0, leftTopCornerCtrlRect);
  addHitNode(EditorHitNodeType::kBoundCorner, 1, leftTopCornerCtrlRect.makeOffset(width, 0));
  addHitNode(EditorHitNodeType::kBoundCorner, 2, leftTopCornerCtrlRect.makeOffset(width, height));
  addHitNode(EditorHitNodeType::kBoundCorner, 3, leftTopCornerCtrlRect.makeOffset(0, height));

  auto leftTopRotateCtrRect = leftTopCornerCtrlRect.makeOffset(-kCornerCtrlNodeSize, -kCornerCtrlNodeSize);
  addHitNode(EditorHitNodeType::kBoundRotate, 0, leftTopRotateCtrRect);
  addHitNode(EditorHitNodeType::kBoundRotate, 1, leftTopRotateCtrRect.makeOffset(width + kCornerCtrlNodeSize, 0));
  addHitNode(EditorHitNodeType::kBoundRotate, 2, leftTopRotateCtrRect.makeOffset(width + kCornerCtrlNodeSize, height + kCornerCtrlNodeSize));
  addHitNode(EditorHitNodeType::kBoundRotate, 3, leftTopRotateCtrRect.makeOffset(0, height + kCornerCtrlNodeSize));

  auto leftEdgeCtrlRect = SkRect::MakeXYWH(left - kEdgeCtrlNodeHalfSize, top + kCornerCtrlNodeHalfSize, kEdgeCtrlNodeSize, height - kCornerCtrlNodeSize);
  auto topEdgeCtrlRect = SkRect::MakeXYWH(left + kCornerCtrlNodeHalfSize, top - kEdgeCtrlNodeHalfSize, width - kCornerCtrlNodeSize, kEdgeCtrlNodeSize);
  addHitNode(EditorHitNodeType::kBoundEdge, 0, topEdgeCtrlRect);
  addHitNode(EditorHitNodeType::kBoundEdge, 1, leftEdgeCtrlRect.makeOffset(width, 0));
  addHitNode(EditorHitNodeType::kBoundEdge, 2, topEdgeCtrlRect.makeOffset(0, height));
  addHitNode(EditorHitNodeType::kBoundEdge, 3, leftEdgeCtrlRect);
}

void BoundEditor::bindEvents() {
  editor_->addEventListener(EventType::kMouseDrag, [this](Event* event) {
    handleMouseDrag(event);
  });
  editor_->addEventListener(EventType::kMouseMove, [this](Event* event) {
    handleMouseMove(event);
  });
}

void BoundEditor::handleDragBound(Event* event) {
  auto& actionSystem = editor_->desaina->actionSystem;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto selectedNodes = editor_->getEditingNodes();
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;
  
  for (auto node : selectedNodes) {
    auto m = util::getTransfromMatrix(node);
    m.postTranslate(deltaX, deltaY);
    PropertyType type = PropertyType::kTransform;
    PropertyValue transform = util::toMatrix(m);
    actionSystem.addAction(UpdatePropertiesAction::Make(node->get_guid(), type, transform));
  }
  editor_->setDirty();
}

void BoundEditor::hanldeDrageCtrlNode(Event* event) {
  auto* hitNode = editor_->getFirstSelectedHitNode();
  if (!hitNode) {
    return;
  }

  switch (hitNode->type) {
    case EditorHitNodeType::kBoundCorner: {
      handleDragBoundResize(event);
      break;
    }
    case EditorHitNodeType::kBoundEdge: {
      handleDragBoundEdge(event);
      break;
    }
    case EditorHitNodeType::kBoundRotate: {
      handleDragBoundRotate(event);
      break;
    }
  }
}

void BoundEditor::handleDragBoundResize(Event* event) {
  auto selectedNodes = editor_->getEditingNodes();
  if (selectedNodes.size() == 1) {
    auto mouseEvent = *static_cast<MouseEvent*>(event);
    auto* node = selectedNodes[0];
    auto deltaX = mouseEvent.deltaX;
    auto deltaY = mouseEvent.deltaY;
    auto localX = mouseEvent.localX;
    auto localY = mouseEvent.localY;
    auto oldeX = localX - deltaX;
    auto oldeY = localY - deltaY;
    auto size = util::getSize(node);
    float angle = base::linesAngle(SkPoint::Make(oldeX - size.x, oldeY - size.y), SkPoint::Make(localX - size.x, localY - size.y));


    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::MakeResizeDelta(node, deltaX, deltaY));
    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::MakeTranslate(node, deltaX, deltaY));

  } else {}
}

void BoundEditor::handleDragBoundRotate(Event* event) {
  auto selectedNodes = editor_->getEditingNodes();
  if (selectedNodes.size() == 1) {
    auto mouseEvent = *static_cast<MouseEvent*>(event);
    auto* node = selectedNodes[0];
    auto deltaX = mouseEvent.deltaX;
    auto deltaY = mouseEvent.deltaY;
    auto localX = mouseEvent.localX;
    auto localY = mouseEvent.localY;
    auto oldeX = localX - deltaX;
    auto oldeY = localY - deltaY;
    auto size = util::getSize(node);
    float angle = base::linesAngle(SkPoint::Make(oldeX - size.x, oldeY - size.y), SkPoint::Make(localX - size.x, localY - size.y));

  } else {}
}

void BoundEditor::handleDragBoundEdge(Event* event) {
  auto* hitNode = editor_->getFirstSelectedHitNode();
  if (!hitNode) {
    return;
  }
  auto mouseEvent = static_cast<MouseEvent*>(event);
  if (isFirstDiagonal(hitNode)) {
    mouseEvent->deltaX = 0;
  } else {
    mouseEvent->deltaY = 0;
  }
  inverseDelta(hitNode, mouseEvent);
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;

  auto selectedNodes = editor_->getEditingNodes();
  if (selectedNodes.size() == 1) {
    auto* node = selectedNodes[0];
    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::MakeResizeDelta(node, deltaX, deltaY));
    if (!shouldInverse(hitNode)) return;
    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::MakeTranslate(node, deltaX, deltaY));

  } else {}
}

void BoundEditor::handleMouseDrag(Event* event) {
  if (editor_->getFirstSelectedHitNode()) {
    hanldeDrageCtrlNode(event);
  } else {
    handleDragBound(event);
  }
}

void BoundEditor::handleMouseMove(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto* hoverNode = editor_->getHoverHitNode();
  auto cursorType = CursorType::kDefault;
  if (hoverNode) {
    switch (hoverNode->type) {
      case EditorHitNodeType::kBoundEdge: {
        cursorType = hoverNode->index % 2 == 0 ? CursorType::kSIZENS : CursorType::kSIZEWE;
        break;
      }
      case EditorHitNodeType::kBoundCorner: {
        cursorType = hoverNode->index % 2 == 0 ? CursorType::kSIZENWSE : CursorType::kSIZENESW;
        break;
      }
      case EditorHitNodeType::kBoundRotate: {
        cursorType = CursorType::kHandle;
        break;
      }
      default: {
        break;
      }
    }
    event->stop();
  }
  editor_->desaina->setCursor(cursorType);
}

void BoundEditor::getPath(SkPath& fillPath, SkPath& strokePath) {
  auto& bound = editor_->getEditBound();
  strokePath.addRect(bound);
  
  constexpr float kCornerCtrlNodeSize = 5;
  constexpr float kCornerCtrlNodeHalfSize = kCornerCtrlNodeSize / 2;
  auto [left, top, right, bottom] = bound;
  auto width = bound.width();
  auto height = bound.height();
  auto leftTopCornerCtrlRect = SkRect::MakeXYWH(left - kCornerCtrlNodeHalfSize, top - kCornerCtrlNodeHalfSize, kCornerCtrlNodeSize, kCornerCtrlNodeSize);
  fillPath.addRect(leftTopCornerCtrlRect);
  fillPath.addRect(leftTopCornerCtrlRect.makeOffset(width, 0));
  fillPath.addRect(leftTopCornerCtrlRect.makeOffset(width, height));
  fillPath.addRect(leftTopCornerCtrlRect.makeOffset(0, height));
}


