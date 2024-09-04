#pragma once

#include "listener.h"
#include "node.h"
#include "node.h"
#include <functional>

namespace dea::interaction {

using GetIntersectBound = std::function<node::Size(node::Vector)>;

class Interaction;
class Selection : public InteractionListener {
public:
  Selection(const GetIntersectBound& getIntersectBound, const node::NodeIterWithWorldMatrix& iter) : getIntersectBound_(getIntersectBound), iter_(iter) {}
  bool empty() const { return selection_.empty(); }
  node::NodeAraryConstRef getSelection() const { return selection_; }
  void clear() { selection_.clear(); hoverNode_ = nullptr; }
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }
  void setIter(const node::NodeIterWithWorldMatrix& iter) { iter_ = iter; }

private:
  node::NodeArary selection_;
  node::Node* hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  node::NodeIterWithWorldMatrix iter_;

	void setSelection(const std::vector<node::Node*>& nodes);
  void setSelection(const std::vector<node::GUID>& nodesIds);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
};

}