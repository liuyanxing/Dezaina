#include "selection.h"
#include "core/SkMatrix.h"
#include "core/SkSize.h"
#include "dezaina.h"
#include "node/src/node-base/node.h"
#include "utility.h"
#include "utility/node_utility.h"
#include "utility/coords.h"

namespace dea::interaction {

using namespace node;
using namespace event;

void Selection::onMouseMove(MouseEvent& event) {
  node::NodeArary nodes;
  auto& dezaina = Dezaina::instance();
  auto& viewport = dezaina.getViewport();
  float radius = 6;

  while (iter_.isValid()) {
    auto* node = iter_.get();
    if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
      auto local = utility::mapPointToLocal({event.worldX, event.worldY}, iter_.getWorldMatrix());
      local = viewport.mapWorldToScreen(local);
      event.screenLocalX = local.x(); event.screenLocalY = local.y();
      auto localRect = SkRect::MakeXYWH(local.x() - radius / 2, local.y() - radius / 2, radius, radius);
      auto size = shape->getSize();
      auto [width, height] = getIntersectBound_(shape->getSize());
      auto bound = SkRect::MakeXYWH(0, 0, width, height);
      if (bound.intersects(localRect)) {
        nodes.push_back(node);
      }
    }
    ++iter_;
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
