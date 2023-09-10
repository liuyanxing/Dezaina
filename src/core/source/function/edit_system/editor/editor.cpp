#include "editor.h"
#include "desaina.h"
#include "event_system/event.h"
#include "event_system/ui_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkScalar.h"
#include "util/node_geometry.h"
#include "base/math.h"
#include "config/editor.h"

void Editor::init() {
  update();
  bindEvents();
}

void Editor::bindEvents() {
  addEventListener(EventType::kAny, [this](Event* event) {
    if (event->isMouseEvent()) {
      handleMouseEvent(event);
    }
  });
}

vector<Node*> Editor::getEditingNodes() {
  return desaina->document.getSelectedNodes();
}

void Editor::buildEditingNodesBound() {
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

void Editor::handleMouseEvent(Event* event) {
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

void Editor::handleMouseDown(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  selected_hit_nodes_.clear();
  if (hover_hit_node_) {
    selected_hit_nodes_.push_back(hover_hit_node_);
    event->stop();
  }
}

void Editor::handleMouseUp(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
}

void Editor::handleMouseMove(Event* event) {
  auto raduis = Config::editorMouseRadius;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto localX = mouseEvent->localX;
  auto localY = mouseEvent->localY;
  auto hitNode = hit_tester->getNodesIntersectWithRect(SkRect::MakeXYWH(localX - raduis, localY - raduis, raduis * 2, raduis * 2));
  if (!hitNode.empty()) {
    hover_hit_node_ = static_cast<EditorHitNode*>(hitNode[0]);
  } else {
    hover_hit_node_ = nullptr;
  }
}

void Editor::mapEventToLocal(Event* event) {
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


Node* Editor::getEditNodeById(const std::optional<GUID>& id) {
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

void Editor::rotate(float degrees, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.rotate(degrees, node);

}

void Editor::resize(float width, float height, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.resize(width, height, node);
}

void Editor::translate(float x, float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.translate(x, y, node);
}

void Editor::setRotatation(float degrees, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.setRotate(degrees, node);
}

void Editor::setSize(float width, float height, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.setSize(width, height, node);
}

void Editor::setTranslate(float x, float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.setTranslate(x, y, node);
}

void Editor::setTranslateX(float x, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  auto matrix = util::getWorldMatrix(node, &desaina->document);
  desaina->actionSystem.setTranslate(x, matrix.getTranslateY(), node);
}

void Editor::setTranslateY(float y, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  auto matrix = util::getWorldMatrix(node, &desaina->document);
  desaina->actionSystem.setTranslate(matrix.getTranslateX(), y, node);
}

void Editor::setTransform(const SkMatrix& transform, std::optional<GUID> id) {
  auto* node = getEditNodeById(id);
  if (!node) {
    return;
  }
  desaina->actionSystem.setTransform(transform, node);
}