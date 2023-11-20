#include "editor.h"
#include "desaina.h"
#include "event_system/event.h"
#include "event_system/hit_tester.h"
#include "event_system/ui_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkScalar.h"
#include "util/node_geometry.h"
#include "base/math.h"
#include "config/editor.h"
#include "action_system/action_system.h"

void EditorView::init() {
  update();
  bindEvents();
}

void EditorView::bindEvents() {
  addEventListener(EventType::kAny, [this](Event* event) {
    if (event->isMouseEvent()) {
      handleMouseEvent(event);
    }
  });
}

vector<Node*> EditorView::getEditingNodes() {
  return desaina->document.getSelectedNodes();
}

void EditorView::buildEditingNodesBound() {
  auto selectedNodes = getEditingNodes();
  if (selectedNodes.size() == 1) {
    edit_bound_ = util::getLocalBound(selectedNodes[0]);
    edit_transform_ = util::getWorldMatrix(selectedNodes[0], &desaina->document);
    return;
  }
  
  SkRect bound;
  for (const auto node : selectedNodes) {
    bound.join(util::getWorldAABBBound(node, &desaina->document));
  }
  edit_transform_.reset();
  edit_transform_.setTranslate(bound.x(), bound.y());
  edit_bound_ = {0, 0, bound.width(), bound.height()};
}

void EditorView::handleMouseEvent(Event* event) {
  switch (event->type) {
    case EventType::kMouseDown:
      handleMouseDown(event);
      break;
    case EventType::kMouseMove:
      handleMouseMove(event);
      break;
    case EventType::kMouseUp:
      handleMouseUp(event);
      break;
    default:
      break;
  }
}

void EditorView::handleMouseDown(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  selected_hit_nodes_.clear();
  if (hover_hit_node_) {
    selected_hit_nodes_.push_back(hover_hit_node_);
    event->stop();
  }
}

void EditorView::handleMouseUp(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
}

void EditorView::handleMouseMove(Event* event) {
  auto raduis = Config::editorMouseRadius;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto x = mouseEvent->x;
  auto y = mouseEvent->y;
  hover_hit_node_ = getNodeUnderPoint({x, y});
}

EditorHitNode* EditorView::getNodeUnderPoint(const SkPoint& point) {
  auto [x, y] = base::mapPointToLocal(point, edit_transform_);
  auto raduis = Config::editorMouseRadius;
  auto hitNode = hit_tester->getNodesIntersectWithRect(SkRect::MakeXYWH(x - raduis, y - raduis, raduis * 2, raduis * 2));
  if (!hitNode.empty()) {
    return static_cast<EditorHitNode*>(hitNode[0]);
  } 
  return nullptr;
}

void EditorView::setSelectNodeByPoint(const SkPoint &point) {
  auto hitNode = getNodeUnderPoint(point);
  if (hitNode) {
    selected_hit_nodes_.clear();
    selected_hit_nodes_.push_back(hitNode);
  }
}

void EditorView::mapEventToLocal(Event* event) {
  auto mouseEvent = static_cast<UIEvent*>(event);
  auto selectedNodes = getEditingNodes();
  
  auto point = base::mapPointToLocal({mouseEvent->x, mouseEvent->y}, edit_transform_);
  mouseEvent->localX = point.x();
  mouseEvent->localY = point.y();

  // mouseEvent->deltaY = -1;
  auto localDelta = base::mapVector({mouseEvent->deltaX, mouseEvent->deltaY}, edit_transform_);
  mouseEvent->localDeltaX = localDelta.x();
  mouseEvent->localDeltaY = localDelta.y();
}


Node* EditorView::getEditNodeById(const std::optional<GUID>& id) {
  if (id.has_value()) {
    auto node = desaina->document.getNodeById(id.value());
    return node.has_value() ? node.value() : nullptr;
  }
  auto editingNodes = getEditingNodes();
  if (!editingNodes.empty()) {
    return editingNodes[0];
  }
  return nullptr;
}

void EditorView::rotate(float degrees, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->rotate(degrees, node);

}

void EditorView::resize(float width, float height, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->resize(width, height, node);
}

void EditorView::translate(float x, float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->translate(x, y, node);
}

void EditorView::setRotatation(float degrees, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->setRotate(degrees, node);
}

void EditorView::setSize(float width, float height, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->setSize(width, height, node);
}

void EditorView::setTranslate(float x, float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->setTranslate(x, y, node);
}

void EditorView::setTranslateX(float x, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  auto matrix = util::getWorldMatrix(node, &desaina->document);
  desaina->actionSystem->setTranslate(x, matrix.getTranslateY(), node);
}

void EditorView::setTranslateY(float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  auto matrix = util::getWorldMatrix(node, &desaina->document);
  desaina->actionSystem->setTranslate(matrix.getTranslateX(), y, node);
}

void EditorView::setTransform(const SkMatrix& transform, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem->setTransform(transform, node);
}

void EditorView::updateHitNodes(const vector<EditorHitNode*>& nodes, std::function<bool(EditorHitNode*, EditorHitNode*)> isSameHitNode) {
  auto selectedHitNodes = selected_hit_nodes_;
  selected_hit_nodes_.clear();
  hit_tester->clear();
  EditorHitNode* newHoverNode = nullptr;
  for (auto* node : nodes) {
    auto it = std::find_if(selectedHitNodes.begin(), selectedHitNodes.end(), [node, isSameHitNode](EditorHitNode* selectedNode) {
      return isSameHitNode(node, selectedNode);
    });
    if (it != selectedHitNodes.end()) {
      selected_hit_nodes_.push_back(node);
    }
    if (hover_hit_node_ && isSameHitNode(node, hover_hit_node_)) {
      newHoverNode = node;
    }
    hit_tester->insert(node);
  }
  hover_hit_node_ = newHoverNode;
}
