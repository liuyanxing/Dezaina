#include "document.h"
#include "bound_editor.h"
#include "desaina.h"
#include "edit_system/editor/editor.h"
#include "include/core/SkRect.h"
#include "util/node_geometry.h"
#include "util/skia.h"

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  init();
}

void BoundEditor::init() {
  bindEvents();
  bindInteractionArea();
}

void BoundEditor::addHitNode(const EditorHitNode& node) {
  hit_nodes_.push_back(node);
  editor_->hit_tester->insert(&hit_nodes_.back());
}

void BoundEditor::bindInteractionArea() {
  const auto& bound = editor_->getBound();
  auto screenBound = editor_->desaina->viewPortSystem.mapWorldToScreen(bound);
  constexpr float kCornerCtrlNodeSize = 5;
  constexpr float kEdgeCtrlNodeSize = 1;
  constexpr float kCornerCtrlNodeHalfSize = kCornerCtrlNodeSize / 2;
  constexpr float kEdgeCtrlNodeHalfSize = kEdgeCtrlNodeSize / 2;
  auto [left, top, right, bottom] = screenBound;
  auto width = screenBound.width();
  auto height = screenBound.height();
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

void BoundEditor::hanldeDrageCtrlNode() {
}

void BoundEditor::handleDragBoundCorner() {
}

void BoundEditor::handleDragBoundEdge() {
}

void BoundEditor::handleMouseDrag(Event* event) {
  if (!editor_->getSelectedHitNode().empty()) {
  } else {
    handleDragBound(event);
  }
}


