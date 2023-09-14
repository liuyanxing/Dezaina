#include "vector_node_editor.h"
#include "desaina.h"
#include "desaina_node.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "event_system/hit_tester.h"
#include "include/core/SkRect.h"
#include "text.h"
#include "vector.h"
#include "config/editor.h"
#include <iostream>
#include <variant>

void VectorNodeEditor::init() {
  bindEvents();
  update();
}

void VectorNodeEditor::bindEvents() {
  addEventListener(EventType::kMouseDrag, [this](Event* event) {
    auto mouseEvent = static_cast<MouseEvent*>(event);
    event->stop();
    handleDrag(mouseEvent);
  });
  addEventListener(EventType::kMouseDown, [this](Event* event) {
    auto mouseEvent = static_cast<MouseEvent*>(event);
    event->stop();
  });
}

void VectorNodeEditor::update() {
  node_ = static_cast<VectorNode*>(getEditingNodes()[0]);
  updateSelectedSegments();
  buildInteractionArea();
  if (network_.empty()) {
    buildNetWork();
  }
}

void VectorNodeEditor::updateSelectedSegments() {
  selected_segments_.clear();
  auto& selectedHitNodes = getSelectedHitNode();
  if (selectedHitNodes.empty()) {
    return;
  }
  for (auto* hitNode : selectedHitNodes) {
    auto* controllerNode = static_cast<ControllerNode*>(hitNode);
    for (auto* segment : network_.getSegments()) {
      if (auto* vertex = std::get_if<VectorEditor::Vertex*>(&controllerNode->vertex)) {
        if (segment->hasVertex(*vertex)) {
          selected_segments_.push_back(segment);
        }
      } else if (auto* vector = std::get_if<Vector*>(&controllerNode->vertex)) {
        if (segment->hasTangent(*vector)) {
          selected_segments_.push_back(segment);
        }
      }
    }
  }
}

void VectorNodeEditor::buildInteractionArea() {
  vector<ControllerNode> new_hit_nodes;
  auto addTangentToHitNodes = [&new_hit_nodes](VectorEditor::SegmentVertex* v) {
    if (!v->hasTangent()) {
      return;
    }
    auto t = v->getTangentEnd();
    auto size = Config::roundCtrlNodeRadius * 2;
    auto bound = SkRect::MakeXYWH(t.x - size / 2, t.y - size / 2, size, size);
    new_hit_nodes.push_back(ControllerNode::Make(v->getTangentOffset(), bound));
  };

  for (auto* segment : selected_segments_) {
      auto& [v0, v1] = segment->getVertecies();
      addTangentToHitNodes(v0);
      addTangentToHitNodes(v1);
  }

  for (auto* vertex : network_.getVertecies()) {
    auto x = vertex->x;
    auto y = vertex->y;
    auto size = Config::roundCtrlNodeRadius * 2;
    auto bound = SkRect::MakeXYWH(x - size / 2, y - size / 2, size, size);
    new_hit_nodes.push_back(ControllerNode::Make(vertex, bound));
  }
  vector<EditorHitNode*> new_hit_nodes_ref;
  std::for_each(new_hit_nodes.begin(), new_hit_nodes.end(), [&new_hit_nodes_ref](auto& node) {
    new_hit_nodes_ref.push_back(&node);
  });

  updateHitNodes(new_hit_nodes_ref, [](EditorHitNode* one, EditorHitNode* two) -> bool {
    auto* node1 = static_cast<ControllerNode*>(one);
    auto* node2 = static_cast<ControllerNode*>(two);
    return node1->vertex == node2->vertex;
  });

  hit_nodes_ = std::move(new_hit_nodes);
}

void VectorNodeEditor::buildNetWork() {
  auto blobId = node_->get_vectorData().vectorNetworkBlob;
  auto blob = desaina_->getBlob(blobId);
  network_ = buildNetworkFromBlob(*blob, arena_);
}

void VectorNodeEditor::getPath(SkPath &fillPath, SkPath &strokePath) {
  for (auto* vertex : network_.getVertecies()) {
    fillPath.addCircle(vertex->x, vertex->y , Config::roundCtrlNodeRadius);
    strokePath.addCircle(vertex->x, vertex->y , Config::roundCtrlNodeRadius);
  }
  for (auto* segment : network_.getSegments()) {
    if (isSelected(segment)) {
      auto& [v0, v1] = segment->getVertecies();
      auto t0 = v0->getTangentEnd();
      auto t1 = v1->getTangentEnd();
      fillPath.addCircle(t0.x, t0.y , Config::roundCtrlNodeRadius);
      fillPath.addCircle(t1.x, t1.y, Config::roundCtrlNodeRadius);
    }
  }

}

bool VectorNodeEditor::isSelected(const VectorEditor::Segment* segment) const {
  for (auto* s : selected_segments_) {
    if (s == segment) {
      return true;
    }
  }
  return false;
}

void VectorNodeEditor::getEditPath(SkPath &path) {
  for (auto* segment : network_.getSegments()) {
    auto& [v0, v1] = segment->getVertecies();
    path.moveTo(v0->x(), v0->y());
    auto t0 = v0->getTangentEnd();
    auto t1 = v1->getTangentEnd();
    path.cubicTo(
      t0.x, t0.y,
      t1.x, t1.y,
      v1->x(), v1->y()
    );
    if (isSelected(segment)) {
      path.moveTo(v0->x(), v0->y());
      path.lineTo(t0.x, t0.y);
      path.moveTo(v1->x(), v1->y());
      path.lineTo(t1.x, t1.y);
    }
  }
}

void VectorNodeEditor::handleDrag(MouseEvent *event) {
  for (auto* hitNode : getSelectedHitNode()) {
    auto* controllerNode = static_cast<ControllerNode*>(hitNode);
    if (auto* vertex = std::get_if<VectorEditor::Vertex*>(&controllerNode->vertex)) {
      auto v = *vertex;
      v->x += event->localDeltaX;
      v->y += event->localDeltaY;
    } else if (auto* vector = std::get_if<Vector*>(&controllerNode->vertex)) {
      auto v = *vector;
      v->x += event->localDeltaX;
      v->y += event->localDeltaY;
    }
  }
}
