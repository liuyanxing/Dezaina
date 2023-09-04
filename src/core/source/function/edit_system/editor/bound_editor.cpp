#include "document.h"
#include "bound_editor.h"
#include "desaina.h"
#include "edit_system/editor/editor.h"
#include "event_system/hit_tester.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include "util/node_geometry.h"
#include "util/skia.h"
#include <iostream>

static bool isFirstDiagonal(EditorHitNode* node) {
  return node->index % 2 == 0;
}

static bool shouldInverse(EditorHitNode* node) {
  return node->index % 3 == 0;
}

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  init();
}

void BoundEditor::init() {
  bindEvents();
  bindInteractionArea();
}

void BoundEditor::addHitNode(const EditorHitNode& node) {
  hit_nodes_.push_back(node);
  auto* hit_node = &hit_nodes_.back();
  editor_->hit_tester->insert(hit_node);
}

void BoundEditor::bindInteractionArea() {
  const auto& bound = editor_->getBound();
  constexpr float kCornerCtrlNodeSize = 5;
  constexpr float kEdgeCtrlNodeSize = 1;
  constexpr float kCornerCtrlNodeHalfSize = kCornerCtrlNodeSize / 2;
  constexpr float kEdgeCtrlNodeHalfSize = kEdgeCtrlNodeSize / 2;
  auto [left, top, right, bottom] = bound;
  auto width = bound.width();
  auto height = bound.height();
  auto leftTopCornerCtrlRect = SkRect::MakeXYWH(left - kCornerCtrlNodeHalfSize, top - kCornerCtrlNodeHalfSize, kCornerCtrlNodeSize, kCornerCtrlNodeSize);
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundCorner, 0, leftTopCornerCtrlRect));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundCorner, 1, leftTopCornerCtrlRect.makeOffset(width, 0)));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundCorner, 2, leftTopCornerCtrlRect.makeOffset(width, height)));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundCorner, 3, leftTopCornerCtrlRect.makeOffset(0, height)));

  auto leftEdgeCtrlRect = SkRect::MakeXYWH(left - kEdgeCtrlNodeHalfSize, top + kCornerCtrlNodeHalfSize, kEdgeCtrlNodeSize, height - kCornerCtrlNodeSize);
  auto topEdgeCtrlRect = SkRect::MakeXYWH(left + kCornerCtrlNodeHalfSize, top - kEdgeCtrlNodeHalfSize, width - kCornerCtrlNodeSize, kEdgeCtrlNodeSize);
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundEdge, 0, topEdgeCtrlRect));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundEdge, 1, leftEdgeCtrlRect.makeOffset(width, 0)));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundEdge, 2, topEdgeCtrlRect.makeOffset(0, height)));
  addHitNode(EditorHitNode::Make(EditorHitNodeType::kBoundEdge, 3, leftEdgeCtrlRect));
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
      handleDragBoundCorner(event);
      break;
    }
    case EditorHitNodeType::kBoundEdge: {
      handleDragBoundEdge(event);
      break;
    }
  }
}

void BoundEditor::handleDragBoundCorner(Event* event) {
}

void BoundEditor::handleDragBoundEdge(Event* event) {
  auto* hitNode = editor_->getFirstSelectedHitNode();
  if (!hitNode) {
    return;
  }
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;
  if (isFirstDiagonal(hitNode)) {
    deltaX = 0;
  } else {
    deltaY = 0;
  }
  bool isInverse = shouldInverse(hitNode);
  if (isInverse) {
    deltaX = -deltaX;
    deltaY = -deltaY;
  }

  std::cout << "drag bound edge: " << deltaX << ", " << deltaY <<  std::endl;

  auto selectedNodes = editor_->getEditingNodes();
  for (auto node : selectedNodes) {
    auto bound = util::getLocalBound(node);
    Vector size{bound.width() + deltaX, bound.height() + deltaY};
    PropertyType sizeType = PropertyType::kSize;
    PropertyValue sizeValue = size;
    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::Make(node->get_guid(), sizeType, sizeValue));
    if (!isInverse) {
      continue;
    }
    
    auto m = util::getTransfromMatrix(node);
    m.postTranslate(-deltaX, -deltaY);
    PropertyType type = PropertyType::kTransform;
    PropertyValue transform = util::toMatrix(m);
    editor_->desaina->actionSystem.addAction(UpdatePropertiesAction::Make(node->get_guid(), type, transform));
  }
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
      default: {
        break;
      }
    }
    event->stop();
  }
  editor_->desaina->setCursor(cursorType);
}


