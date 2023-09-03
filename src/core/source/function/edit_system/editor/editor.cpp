#include "editor.h"
#include "desaina.h"

vector<Node*> Editor::getEditingNodes() {
  auto selectedNodes = desaina->document.getSelectedNodes();
  return selectedNodes;
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
  emit(event);
}

void Editor::handleMouseDown(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  if (hover_hit_node_) {
    selected_hit_nodes_.push_back(hover_hit_node_);
  }
}

void Editor::handleMouseMove(Event* event) {
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto clientX = mouseEvent->clientX;
  auto clientY = mouseEvent->clientY;
  hover_hit_node_ = static_cast<EditorHitNode*>(hit_tester_->getNodeUnderPoint(clientX, clientY));
}

