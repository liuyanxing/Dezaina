#include "selection.h"
#include "core/SkMatrix.h"
#include "core/SkSize.h"
#include "dezaina.h"
#include "node/src/node-base/node.h"
#include "spdlog/spdlog.h"
#include "utility.h"
#include "utility/node_utility.h"
#include "utility/coords.h"
#include <algorithm>

namespace dea::interaction {

using namespace node;
using namespace event;

void Selection::onMouseMove(MouseEvent& event) {
  node::NodeArary nodes;
  auto& dezaina = Dezaina::instance();
  auto& viewport = dezaina.getViewport();
  float radius = 6;
  auto iter = iter_;

  while (iter.isValid()) {
    auto* node = iter.get();
    if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
      auto matrix = viewport.getVPMatrix() * iter.getWorldMatrix();
      auto local = utility::mapPointToLocal({event.x, event.y}, matrix);
      event.localX = local.x(); event.localY = local.y();
      auto cursorRect = SkRect::MakeXYWH(local.x() - radius, local.y() - radius, 2 * radius, 2 * radius);
      auto [width, height] = getIntersectBound_(shape->getSize());
      auto bound = SkRect::MakeXYWH(0, 0, width, height);
      spdlog::info("local: x: {}, y: {}", local.x(), local.y());
      if (bound.intersects(cursorRect)) {
        nodes.push_back(node);
      }
    }
    ++iter;
  }

  if (nodes.empty()) {
    hoverNode_ = nullptr;
    return;
  }
  hoverNode_ = nodes[0];
  event.target = hoverNode_;
}

void Selection::onMouseDown(MouseEvent& event) {
  if (hoverNode_ != nullptr) {
    if (std::find(selection_.begin(), selection_.end(), hoverNode_) != selection_.end()) {
      return;
    }
    event.target = hoverNode_;
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
