#pragma once

#include "listener.h"
#include "node.h"
#include "node.h"
#include "node/node.h"
#include "node/node_base.generated.h"
#include <functional>

namespace dea::interaction {

using GetIntersectBound = std::function<node::Vector(node::Vector)>;
using OnSelectionChangeCb = std::function<void(const node::NodeConstArary&)>;

inline node::Vector DefaultGetIntersectBound(node::Vector size) {
  return size;
}

class Interaction;
class Selection : public InteractionListener {
public:
  Selection(node::NodeConstPtr node, const GetIntersectBound& getIntersectBound = DefaultGetIntersectBound) : root_(node), getIntersectBound_(getIntersectBound) {}
  bool empty() const { return selection_.empty(); }
  const node::NodeConstArary& getSelection() const { return selection_; }
  void clear() { selection_.clear(); hoverNode_ = nullptr; }
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }
  void setRoot(node::NodeConstPtr node) { root_ = node; }
  void onSelectionChange(const OnSelectionChangeCb& callback) { onSelectionChangeCb_ = callback; }
	void setSelection(const node::NodeConstArary& nodes);

private:
  node::NodeConstArary selection_;
  node::NodeConstPtr hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  node::NodeConstPtr root_;
  OnSelectionChangeCb onSelectionChangeCb_;

  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
};

}