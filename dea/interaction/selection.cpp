#include "selection.h"
#include "dezaina.h"
#include "node/node.h"
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
  hoverNode_ = root_;
  float radius = 3;
  // todo remove const_cast
  auto iter = NodeIterWithWorldMatrix(const_cast<Node *>(root_));

  while (iter.isValid()) {
    auto *node = iter.get();
    if (auto *shape = node::node_cast<DefaultShapeNode>(node)) {
      auto matrix = viewport.getVPMatrix() * iter.getWorldMatrix();
      setEventLocalPosition(event, iter);
      auto cursorRect = Rect{event.localX - radius, event.localY - radius,
                             2 * radius, 2 * radius};
      auto [width, height] = getIntersectBound_(shape->getSize());
      auto bound = Rect{0, 0, width, height};
      // spdlog::info("local: x: {}, y: {}", local.x(), local.y());
      if (bound.intersects(cursorRect) && mouseHoverFilter(node)) {
        hoverNode_ = node;
      }
    }
    ++iter;
  }
  onHoverCb_(hoverNode_);

  event.target = const_cast<node::NodePtr>(hoverNode_);
}

void Selection::onMouseDown(MouseEvent &event) {
  if (hoverNode_ && !node::node_cast<node::PageNode>(hoverNode_)) {
    if (std::find(selection_.begin(), selection_.end(), hoverNode_) !=
        selection_.end()) {
      return;
    }
    setSelection({hoverNode_});
  } else {
    event.target = const_cast<node::NodePtr>(root_);
    setSelection(node::NodeConstArary{});
  }
  event.target = const_cast<node::NodePtr>(hoverNode_);
}

void Selection::setSelection(const node::NodeConstArary &nodes) {
  if (!nodes.empty()) {
    hoverNode_ = nullptr;
  }

  selection_ = nodes;
  if (onSelectionChangeCb_) {
    onSelectionChangeCb_(selection_);
  }
}

} // namespace dea::interaction
