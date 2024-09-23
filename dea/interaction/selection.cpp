#include "selection.h"
#include "dezaina.h"
#include "node/utility.h"
#include "spdlog/spdlog.h"
#include "utility.h"
#include "utility/coords.h"
#include <algorithm>

namespace dea::interaction {

using namespace node;
using namespace event;

void Selection::onMouseMove(MouseEvent &event) {
  auto &dezaina = Dezaina::instance();
  auto &viewport = dezaina.getViewport();
  hoverNode_ = nullptr;
  float radius = 3;
  // todo remove const_cast
  auto iter = NodeIterWithWorldMatrix(const_cast<Node*>(root_));

  while (iter.isValid()) {
    auto *node = iter.get();
    if (auto *shape = node::node_cast<node::DefaultShapeNode>(node)) {
      auto matrix = viewport.getVPMatrix() * iter.getWorldMatrix();
      setEventLocalPosition(event, iter);
      auto cursorRect = Rect{event.localX - radius, event.localY - radius,
                             2 * radius, 2 * radius};
      auto [width, height] = getIntersectBound_(shape->getSize());
      auto bound = Rect{0, 0, width, height};
      // spdlog::info("local: x: {}, y: {}", local.x(), local.y());
      if (bound.intersects(cursorRect)) {
        hoverNode_ = node;
      }
    }
    ++iter;
  }

  if (!hoverNode_) {
    return;
  }
  event.target = hoverNode_;
}

void Selection::onMouseDown(MouseEvent &event) {
  if (hoverNode_ != nullptr) {
    if (std::find(selection_.begin(), selection_.end(), hoverNode_) !=
        selection_.end()) {
      return;
    }
    event.target = hoverNode_;
    setSelection({hoverNode_});
    if (onSelectionChangeCb_)
      onSelectionChangeCb_(selection_);
  } else {
    setSelection(std::vector<Node *>{});
  }
}

void Selection::setSelection(const std::vector<Node *> &nodes) {
  if (!nodes.empty()) {
    hoverNode_ = nullptr;
  }
  selection_ = nodes;
}

} // namespace dea::interaction
