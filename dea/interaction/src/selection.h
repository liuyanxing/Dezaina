#pragma once

#include <vector>
#include "node.h"
#include "listener.h"

namespace dea::interaction {

class Interaction;
class Selection : public InteractionListener {
public:
  bool empty() const {
    return selection_.empty();
  }
  const std::vector<node::Node*>& getSelection() const {
    return selection_;
  }

  const node::Node* getHoverNode() const {
    return hoverNode_;
  }

private:
  Interaction* interaction_;
  std::vector<node::Node*> selection_;
  node::Node* hoverNode_ = nullptr;


	void setSelection(const std::vector<node::Node*>& nodes);
  void setSelection(const std::vector<node::GUID>& nodesIds);
  void onMouseMove(event::MouseEvent& event) override;
  void onMouseDown(event::MouseEvent& event) override;

};

}