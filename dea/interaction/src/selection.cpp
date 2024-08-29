#include "selection.h"
#include "core/SkMatrix.h"
#include "core/SkSize.h"
#include "dezaina.h"
#include "utility.h"
#include "utility/node_utility.h"
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
      hoverNode_ = nullptr;
    }
    for (auto& node : nodes) {
      if (isCursorOnNodePixel(mouseEvent.worldX, mouseEvent.worldY, node, false)) {
        hoverNode_ = node;
        if (shouldStopEvent_) {
          event.stop();
        }
        break;
      }
    }
  }

}

void Selection::onMouseDown(MouseEvent& event) {
  if (hoverNode_ != nullptr) {
    setSelection({hoverNode_});
    if (shouldStopEvent_) {
      event.stop();
    }
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

SkSize Selection::getSelectionBound() const {
  if (selection_.empty()) {
    return {0, 0};
  }
  if (selection_.size() == 1) {
    return utility::getScreenSize(selection_[0]);
  }

  // todo: multiple selection
  return {0, 0};
}

SkMatrix Selection::getSelectionTransform() const {
  if (selection_.empty()) {
    return SkMatrix::I();
  }
  if (selection_.size() == 1) {
    return utility::getWorldMatrix(selection_[0]);
  }
  return SkMatrix::I();
}

} // namespace dea::interaction
