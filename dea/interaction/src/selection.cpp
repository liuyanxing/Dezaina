#include "selection.h"
#include "dezaina.h"
#include "interaction.h"
#include "utility.h"
#include <iostream>

namespace dea::interaction {

using namespace node;
using namespace event;

void Selection::onMouseMove(MouseEvent& event) {
  std::vector<Node*> nodes;
  auto mouseEvent = static_cast<MouseEvent&>(event);
  auto& dezaina = Dezaina::instance();
  auto& viewport = dezaina.getViewport();
  auto& doc = dezaina.getDocument();

  if (auto* curPage = doc.currentPage()) {
    auto nodes = doc.getNodesWithRadius({event.worldX, event.worldY}, viewport.mapScreenToWorld(6));
    if (nodes.empty()) {
      // mouseEvent->localX = mouseEvent->x;
      // mouseEvent->localY = mouseEvent->y;
      hoverNode_ = nullptr;
    }
    for (auto& node : nodes) {
      if (isCursorOnNodePixel(mouseEvent.worldX, mouseEvent.worldY, node, false)) {
        if (node != hoverNode_) {
          // event->target = node;
          std::cout << "hovering on node" << std::endl;
        }
        hoverNode_ = node;
        auto matrix = utility::getWorldMatrix(node);
        // auto point = utility::mapPointToLocal(matrix, {mouseEvent->x, mouseEvent->y});
        // mouseEvent->localX = point.x();
        // mouseEvent->localY = point.y();
        break;
      }
    }
  }
}

void Selection::onMouseDown(MouseEvent& event) {
  if (hoverNode_ != nullptr) {
    setSelection({hoverNode_});
  } else {
    setSelection(std::vector<Node*>{});
  }
}

void Selection::setSelection(const std::vector<Node*>& nodes) {
  if (!nodes.empty()) {
    hoverNode_ = nullptr;
  } 
  selection_ = nodes;
}

void Selection::setSelection(const std::vector<GUID>& nodesIds) {

}

}
