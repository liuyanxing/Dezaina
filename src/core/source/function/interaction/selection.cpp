#include "selection.h"
#include "interaction.h"

void Selection::bindEvents() {
  addEventListener(EventType::kMouseMove, [this](Event* event) {
    handleMouseMove(event);
  });
  
  addEventListener(EventType::kMouseDown, [this](Event* event) {
    handleMouseDown(event);
  });
}

void Selection::handleMouseMove(Event* event) {
  vector<Node*> nodes;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto* desaina = interaction_->getDezaina();
  auto& nodeUtil = desaina->nodeUtil;
  if (auto* curPage = desaina->document.getCurrentPage()) {
    curPage->getNodesUnderPoint(mouseEvent->x, mouseEvent->y, nodes);
    for (auto& node : nodes) {
      if (interaction_->util.isCursorOnNodePixel(mouseEvent->x, mouseEvent->y, node)) {
        if (node != hoverNode_) {
          event->target = node;
        }
        hoverNode_ = node;
        auto matrix = nodeUtil.getWorldMatrix(node);
        auto point = base::mapPointToLocal({mouseEvent->x, mouseEvent->y}, matrix);
        mouseEvent->localX = point.x();
        mouseEvent->localY = point.y();
        break;
      }
    }
    if (nodes.empty()) {
      mouseEvent->localX = mouseEvent->x;
      mouseEvent->localY = mouseEvent->y;
    }
  }
}

void Selection::handleMouseDown(Event* event) {
  if (hoverNode_ != nullptr) {
    setSelection({hoverNode_});
  } else {
    setSelection(vector<Node*>{});
  }
}

void Selection::setSelection(const vector<Node*>& nodes) {
  if (!nodes.empty()) {
    hoverNode_ = nullptr;
  } 
  selection_ = nodes;
  emitSelectionChange();
}

void Selection::setSelection(const vector<GUID>& nodesIds) {

}

void Selection::emitSelectionChange() {
  UIEvent event;
  event.type = EventType::kSelectionChange;
  emit(event);
}
