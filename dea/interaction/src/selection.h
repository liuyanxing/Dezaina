#pragma once

#include "core/SkMatrix.h"
#include "core/SkSize.h"
#include "listener.h"
#include "node.h"
#include <functional>

namespace dea::interaction {

using GetIntersectBound = std::function<SkRect<SkRect>>;
class Interaction;
class Selection : public InteractionListener {
public:
  Selection(const GetIntersectBound& getIntersectBound, const utility::NodeInterWithWorldMatrix& iter, bool shouldStopEvent) : getIntersectBound_(getIntersectBound), iter_(iter), shouldStopEvent_(shouldStopEvent) {}
  bool empty() const { return selection_.empty(); }
  const NodeArrayRef getSelection() const { return selection_; }
  SkSize getSelectionBound() const;
  SkMatrix getSelectionTransform() const;
  node::NodeConstPtr getHoverNode() const { return hoverNode_; }

private:
  Interaction* interaction_;
  std::vector<node::Node*> selection_;
  node::Node* hoverNode_ = nullptr;
  GetIntersectBound getIntersectBound_;
  utility::NodeInterWithWorldMatrix iter_;
  bool shouldStopEvent_;

	void setSelection(const std::vector<node::Node*>& nodes);
  void setSelection(const std::vector<node::GUID>& nodesIds);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;
};

}