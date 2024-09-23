#pragma once

#include "listener.h"
#include "node.h"
#include "node.h"
#include "node/node.h"
#include <functional>

namespace dea::interaction {

using GetIntersectBound = std::function<node::Size(node::Vector)>;
using OnSelectionChangeCb = std::function<void(const node::NodeArary&)>;

class Interaction;
class Selection : public InteractionListener {
public:
  Selection(node::NodeConstPtr node, const GetIntersectBound& getIntersectBound) : root_(node), getIntersectBound_(getIntersectBound) {}
  bool empty() const { return selection_.empty(); }
  node::NodeAraryConstRef getSelection() const { return selection_; }
  void clear() { selection_.clear(); hoverNode_ = nullptr; }
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }
  void setRoot(node::NodeConstPtr node) { root_ = node; }
  void onSelectionChange(const OnSelectionChangeCb& callback) { onSelectionChangeCb_ = callback; }

private:
  node::NodeArary selection_;
  node::Node* hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  node::NodeConstPtr root_;
  OnSelectionChangeCb onSelectionChangeCb_;

	void setSelection(const std::vector<node::Node*>& nodes);
  void setSelection(const std::vector<node::GUID>& nodesIds);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
};

}