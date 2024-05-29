#pragma once

#include "event_system/event_emitter.h"
#include "event_system/mouse_event.h"
#include "event_system/mouse_events_consumer.h"
#include "node_type.h"
#include "base_type.h"
#include <vector>

class Interaction;
class Desaina;

class Selection : public EventEmitter, public EventsConsumer {
public:
  explicit Selection(Interaction* interaction) : EventsConsumer(this), interaction_(interaction) {};

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

	void handleMouseMove(MouseEvent* event) override;
	void handleMouseDown(MouseEvent* event) override;

	void setSelection(const vector<Node*>& nodes);
  void setSelection(const vector<GUID>& nodesIds);

  void emitSelectionChange();
};
