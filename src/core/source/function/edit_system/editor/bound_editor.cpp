#include "document.h"
#include "bound_editor.h"
#include "desaina.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "event_system/hit_tester.h"
#include "event_system/mouse_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include "util/node_geometry.h"
#include "util/skia.h"
#include "base/math.h"
#include "config/editor.h"
#include <iostream>

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  init();
}

void BoundEditor::init() {
  bindEvents();
  bindInteractionArea();
}

void BoundEditor::addHitNode(EditorHitNodeType type, int index, const SkPoint& direction, const SkRect& rect) {
  hit_nodes_.push_back(BoundEditorHitNode::Make(type, index, direction, rect));
  auto* hit_node = &hit_nodes_.back();
  editor_->insertHitNode(hit_node);
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
    editor_->translate(deltaX, deltaY, node->get_guid());
  }
}

void BoundEditor::hanldeDrageCtrlNode(Event* event) {
  auto* hitNode = editor_->getFirstSelectedHitNode();
  if (!hitNode) {
    return;
  }

  switch (hitNode->type) {
    case EditorHitNodeType::kBoundEdge:
    case EditorHitNodeType::kBoundCorner: {
      handleDragBoundResize(event);
      break;
    }
    case EditorHitNodeType::kBoundRotate: {
      handleDragBoundRotate(event);
      break;
    }
  }
}

void BoundEditor::handleDragBoundResize(Event* event) {
  auto* hitNode = static_cast<BoundEditorHitNode*>(editor_->getFirstSelectedHitNode());
  if (!hitNode) {
    return;
  }
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto bound = editor_->getEditBound();
  auto boundTransform = editor_->getEditTransform();
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;
  auto localDeltaX = mouseEvent->localDeltaX;
  auto localDeltaY = mouseEvent->localDeltaY;
  auto sizeDelta = SkVector{localDeltaX, localDeltaY} * hitNode->direction;
  auto translateDeltaX = 0;
  auto translateDeltaY = 0;
  SkMatrix transform;

  if (sizeDelta.x() * localDeltaX < 0) {
    translateDeltaX = -sizeDelta.x();
  }

  if (sizeDelta.y() * localDeltaY < 0) {
    translateDeltaY = -sizeDelta.y();
  }
  auto translate = base::getTranslateOfBound(bound, boundTransform);
  transform.setTranslate(translateDeltaX, translateDeltaY);
  auto rotatation = base::getRotation(boundTransform);
  transform.postRotate(rotatation, bound.width() / 2, bound.height() / 2);
  transform.postTranslate(translate.x(), translate.y());

  auto selectedNodes = editor_->getEditingNodes();
  if (selectedNodes.size() == 1) {
    auto* node = selectedNodes[0];
    editor_->resize(sizeDelta.x(), sizeDelta.y());
    editor_->setTransform(transform);

  } else {}
  
}

void BoundEditor::handleDragBoundRotate(Event* event) {
  auto mouseEvent = *static_cast<MouseEvent*>(event);
  auto bound = editor_->getEditBound();
  auto deltaX = mouseEvent.localDeltaX;
  auto deltaY = mouseEvent.localDeltaY;
  auto localCenterX = mouseEvent.localX - bound.width() / 2;
  auto localCenterY = mouseEvent.localY - bound.height() / 2;
  auto oldCenterX = localCenterX - deltaX;
  auto oldCenterY = localCenterY - deltaY;
 
  auto selectedNodes = editor_->getEditingNodes();
  if (selectedNodes.size() == 1) {
    auto* node = selectedNodes[0];
   float angle = base::vectorsAngle({oldCenterX, oldCenterY}, {localCenterX, localCenterY});
   editor_->rotate(angle);
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
  
  constexpr float kCornerCtrlNodeSize = Config::boundCornerCtrlNodeSize;
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

void BoundEditor::bindInteractionArea() {
  const auto& bound = editor_->getEditBound();
  constexpr float kCornerCtrlNodeSize = Config::boundCornerCtrlNodeSize - 2 * Config::editorMouseRadius;
  constexpr float kRotationCtrlNodeSize = Config::boundCornerCtrlNodeSize;
  constexpr float kEdgeCtrlNodeSize = Config::boundEdgeCtrlNodeWith;
  constexpr float kCornerCtrlNodeHalfSize = kCornerCtrlNodeSize / 2;
  constexpr float kRotationCtrlNodeHalfSize = kRotationCtrlNodeSize / 2;
  constexpr float kEdgeCtrlNodeHalfSize = kEdgeCtrlNodeSize / 2;
  auto [left, top, right, bottom] = bound;
  auto width = bound.width();
  auto height = bound.height();
  auto leftTopCornerCtrlRect = SkRect::MakeXYWH(left - kCornerCtrlNodeHalfSize, top - kCornerCtrlNodeHalfSize, kCornerCtrlNodeSize, kCornerCtrlNodeSize);
  addHitNode(EditorHitNodeType::kBoundCorner, 0, {-1, -1}, leftTopCornerCtrlRect);
  addHitNode(EditorHitNodeType::kBoundCorner, 1, {1, -1}, leftTopCornerCtrlRect.makeOffset(width, 0));
  addHitNode(EditorHitNodeType::kBoundCorner, 2, {1, 1}, leftTopCornerCtrlRect.makeOffset(width, height));
  addHitNode(EditorHitNodeType::kBoundCorner, 3, {-1, 1}, leftTopCornerCtrlRect.makeOffset(0, height));

  auto leftTopRotateCtrRect = leftTopCornerCtrlRect.MakeXYWH(left - kRotationCtrlNodeHalfSize, top - kRotationCtrlNodeHalfSize, kRotationCtrlNodeSize, kRotationCtrlNodeSize);
  leftTopRotateCtrRect = leftTopRotateCtrRect.makeOffset(-kRotationCtrlNodeHalfSize - kCornerCtrlNodeHalfSize, -kRotationCtrlNodeHalfSize - kCornerCtrlNodeHalfSize);
  addHitNode(EditorHitNodeType::kBoundRotate, 0, {0, 0}, leftTopRotateCtrRect);
  addHitNode(EditorHitNodeType::kBoundRotate, 1, {0, 0}, leftTopRotateCtrRect.makeOffset(width + kCornerCtrlNodeSize + kRotationCtrlNodeSize, 0));
  addHitNode(EditorHitNodeType::kBoundRotate, 2,  {0, 0}, leftTopRotateCtrRect.makeOffset(width + kCornerCtrlNodeSize + kRotationCtrlNodeSize, height + kCornerCtrlNodeSize + kRotationCtrlNodeSize));
  addHitNode(EditorHitNodeType::kBoundRotate, 3, {0, 0}, leftTopRotateCtrRect.makeOffset(0, height + kCornerCtrlNodeSize + kRotationCtrlNodeSize));

  auto leftEdgeCtrlRect = SkRect::MakeXYWH(left - kEdgeCtrlNodeHalfSize, top + kCornerCtrlNodeHalfSize, kEdgeCtrlNodeSize, height - kCornerCtrlNodeSize);
  auto topEdgeCtrlRect = SkRect::MakeXYWH(left + kCornerCtrlNodeHalfSize, top - kEdgeCtrlNodeHalfSize, width - kCornerCtrlNodeSize, kEdgeCtrlNodeSize);
  addHitNode(EditorHitNodeType::kBoundEdge, 0, {0, -1}, topEdgeCtrlRect);
  addHitNode(EditorHitNodeType::kBoundEdge, 1, {1, 0}, leftEdgeCtrlRect.makeOffset(width, 0));
  addHitNode(EditorHitNodeType::kBoundEdge, 2, {0, 1}, topEdgeCtrlRect.makeOffset(0, height));
  addHitNode(EditorHitNodeType::kBoundEdge, 3, {-1, 0}, leftEdgeCtrlRect);
}
