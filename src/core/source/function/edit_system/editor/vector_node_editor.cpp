#include "vector_node_editor.h"
#include "desaina.h"
#include "include/core/SkRect.h"
#include "text.h"
#include "vector.h"
#include "config/editor.h"

void VectorNodeEditor::init() {
  bindEvents();
  update();
}

void VectorNodeEditor::bindEvents() {
  addEventListener(EventType::kMouseDrag, [this](Event* event) {
    auto mouseEvent = static_cast<MouseEvent*>(event);
    event->stop();
    hanleDrag(mouseEvent);
  });
}

void VectorNodeEditor::update() {
  node_ = static_cast<VectorNode*>(getEditingNodes()[0]);
  buildNetWork();
}

void VectorNodeEditor::addHitNode(EditorHitNodeType type, void* data, const SkRect& rect) {
  hit_nodes_.push_back(EditorHitNode::Make(type, data, rect));
  hit_tester->insert(&hit_nodes_.back());
}

void VectorNodeEditor::bindInteractionArea() {
  hit_nodes_.clear();
  for (auto* vertex : network_.getVertecies()) {
    auto x = vertex->x;
    auto y = vertex->y;
    auto size = Config::roundCtrlNodeRadius * 2;
    auto bound = SkRect::MakeXYWH(x - size / 2, y - size / 2, size, size);
    addHitNode(EditorHitNodeType::kController, vertex, bound);
  }
}

void VectorNodeEditor::buildNetWork() {
  getEditingNodes();
  auto blobId = node_->get_vectorData().vectorNetworkBlob;
  auto blob = desaina_->getBlob(blobId);
  network_ = buildNetworkFromBlob(*blob, arena_);
}

void VectorNodeEditor::getPath(SkPath &fillPath, SkPath &strokePath) {
  for (auto* vertex : network_.getVertecies()) {
    fillPath.addCircle(vertex->x, vertex->y , Config::roundCtrlNodeRadius);
    strokePath.addCircle(vertex->x, vertex->y , Config::roundCtrlNodeRadius);
  }
}

void VectorNodeEditor::getEditPath(SkPath &path) {
  for (auto* segment : network_.getSegments()) {
    auto& [v0, v1] = segment->getVertecies();
    path.moveTo(v0->x(), v0->y());
    auto tangentOffset0 = v0->getTangentOffset();
    auto tangentOffset1 = v1->getTangentOffset();
    path.cubicTo(
      v0->x() + tangentOffset0.x, v0->y() + tangentOffset0.y,
      v1->x() + tangentOffset1.x, v1->y() + tangentOffset1.y,
      v1->x(), v1->y()
    );
  }
}


void VectorNodeEditor::hanleDrag(MouseEvent *event) {
  for (auto* hitNode : getSelectedHitNode()) {

  }
}