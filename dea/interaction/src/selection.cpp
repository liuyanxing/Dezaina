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
      auto& matrix = viewport.getVPMatrix() * iter_.getWorldMatrix();
      auto local = utility::mapPointToLocal({event.screenX, event.screenY}, matrix);
      auto cursorRect = SkRect::MakeXYWH(local.x - radius, local.y - radius, 2 * radius, 2 * radius);
      auto [width, height] = getIntersectBound_(shape->getSize());
      auto bound = SkRect::MakeXYWH(0, 0, width, height);
      if (bound.intersects(cursorRect)) {
        nodes.push_back(node);
      }
    }
    ++iter_;
  }
 
}

void Selection::onMouseDown(MouseEvent& event) {
  if (hoverNode_ != nullptr) {
    if (selections_.find(hoverNode_) != selections_.end()) {
      return;
    }
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
