#pragma once

#include "core/SkMatrix.h"
#include "core/SkSize.h"
#include "listener.h"
#include "node.h"
#include "node.h"
#include <functional>
#include "utility/node_utility.h"

namespace dea::interaction {

using GetIntersectBound = std::function<SkSize(node::Vector)>;

class Interaction;
class Selection : public InteractionListener {
public:
  Selection(const GetIntersectBound& getIntersectBound, const utility::NodeIterWithWorldMatrix& iter) : getIntersectBound_(getIntersectBound), iter_(iter) {}
  bool empty() const { return selection_.empty(); }
  node::NodeAraryConstRef getSelection() const { return selection_; }
  void clear() { selection_.clear(); hoverNode_ = nullptr; }
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }
  void setIter(const utility::NodeIterWithWorldMatrix& iter) { iter_ = iter; }

private:
  node::NodeArary selection_;
  node::Node* hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  utility::NodeIterWithWorldMatrix iter_;

	void setSelection(const std::vector<node::Node*>& nodes);
  void setSelection(const std::vector<node::GUID>& nodesIds);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
};

}