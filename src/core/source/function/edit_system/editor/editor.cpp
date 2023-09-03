#include "editor.h"
#include "desaina.h"
#include "event_system/ui_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkScalar.h"
#include "util/node_geometry.h"
#include "base/math.h"

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
  auto selectedNodes = desaina->document.getSelectedNodes();
  return selectedNodes;
}

SkRect Editor::buildEditingNodesBound() {
  auto selectedNodes = getEditingNodes();
  if (selectedNodes.size() == 1) {
    return util::getLocalBound(selectedNodes[0]);
  }
  
  SkRect bound;
  for (const auto node : selectedNodes) {
    bound.join(util::getWorldAABBBound(node, &desaina->document));
  }
  return bound;
}

void Editor::handleMouseEvent(Event* event) {
  switch (event->type) {
    case EventType::kMouseDown:
      handleMouseDown(event);
      break;
    case EventType::kMouseMove:
      handleMouseMove(event);
      break;
    default:
      break;
  }
}

void Editor::handleMouseDown(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  if (hover_hit_node_) {
    selected_hit_nodes_.push_back(hover_hit_node_);
  }
}

void Editor::handleMouseMove(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto localX = mouseEvent->localX;
  auto localY = mouseEvent->localY;
  auto hitNode = hit_tester->getNodesIntersectWithRect(SkRect::MakeXYWH(localX - 3, localY - 3, 6, 6));
  if (!hitNode.empty()) {
    hover_hit_node_ = static_cast<EditorHitNode*>(hitNode[0]);
  } else {
    hover_hit_node_ = nullptr;
  }
}

void Editor::mapEventToLocal(Event* event) {
  update();
  auto mouseEvent = static_cast<UIEvent*>(event);
  auto selectedNodes = getEditingNodes();
  
  SkMatrix matrix;
  if (selectedNodes.size() == 1) {
    matrix = util::getWorldMatrix(selectedNodes[0], &desaina->document);
  } else {
    auto matrix = SkMatrix::I();
    matrix.setTranslate(bound_.x(), bound_.y());
  }
  auto point = base::mapPointToLocal(mouseEvent->x, mouseEvent->y, matrix);
  auto deltaPointX = base::mapPointToLocal(mouseEvent->deltaX, 0, matrix);
  auto deltaPointY = base::mapPointToLocal(mouseEvent->deltaY, 0, matrix);
  mouseEvent->localX = point.x();
  mouseEvent->localY = point.y();
  // mouseEvent->deltaX = deltaPointX.x() - deltaPointX.y();
  // mouseEvent->deltaY = deltaPointY.y() - deltaPointY.x();
}
