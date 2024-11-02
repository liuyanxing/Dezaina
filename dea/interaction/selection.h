#pragma once

#include "listener.h"
#include "node.h"
#include "node/node.h"
#include "node/node_base.generated.h"
#include <functional>

namespace dea::interaction {

using GetIntersectBound = std::function<node::Vector(node::Vector)>;
using OnSelectionChangeCb = std::function<void(const node::NodeConstArary &)>;
using MouseHoverFilter = std::function<bool(node::NodeConstPtr)>;
using HoverCb = std::function<void(node::NodeConstPtr)>;

inline node::Vector DefaultGetIntersectBound(node::Vector size) { return size; }

class Interaction;
class Selection : public InteractionListener {
public:
  Selection(node::NodeConstArary &selection, node::NodeConstPtr root,
            GetIntersectBound getBound = DefaultGetIntersectBound)
      : selection_(selection), root_(root), getIntersectBound_(getBound) {}
  bool empty() const { return selection_.empty(); }
  const node::NodeConstArary &getSelection() const { return selection_; }
  void clear() {
    selection_.clear();
    hoverNode_ = nullptr;
  }
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }
  void setRoot(node::NodeConstPtr node) { root_ = node; }
  void onSelectionChange(const OnSelectionChangeCb &callback) {
    onSelectionChangeCb_ = callback;
  }
  void setSelection(const node::NodeConstArary &nodes);

  void setMouseHoverFilter(const MouseHoverFilter &callback) {
    mouseHoverFilter = callback;
  }
  void onHover(const HoverCb &callback) { onHoverCb_ = callback; }

private:
  node::NodeConstArary &selection_;
  node::NodeConstPtr hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  node::NodeConstPtr root_;
  OnSelectionChangeCb onSelectionChangeCb_;
  MouseHoverFilter mouseHoverFilter = [](node::NodeConstPtr) { return true; };
  HoverCb onHoverCb_ = [](node::NodeConstPtr) {};

  void onMouseMove(event::MouseEvent &event) override;
  void onMouseDown(event::MouseEvent &event) override;
};

} // namespace dea::interaction
