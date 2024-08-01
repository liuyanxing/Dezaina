#pragma once

#include "event_system/event_emitter.h"
#include "event_system/mouse_event.h"
#include "event_system/listener.h"
#include "node_type.h"
#include "base_type.h"

namespace dea::interaction {

class Interaction;
class Selection : public EventEmitter, public Listener {
public:
  explicit Selection(Interaction* interaction) : Listener(), interaction_(interaction) {};

  bool empty() const {
    return selection_.empty();
  }
  const vector<Node*>& getSelection() const {
    return selection_;
  }

  const Node* getHoverNode() const {
    return hoverNode_;
  }

private:
  Interaction* interaction_;
  vector<Node*> selection_;
  Node* hoverNode_ = nullptr;

	void onMouseMove(MouseEvent* event) override;
	void onMouseDown(MouseEvent* event) override;

	void setSelection(const vector<Node*>& nodes);
  void setSelection(const vector<GUID>& nodesIds);

  void emitSelectionChange();
};

}