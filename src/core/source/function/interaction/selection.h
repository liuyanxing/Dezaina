#pragma once

#include "desaina.h"
#include "event_system/event_emitter.h"
#include "node_type.h"
#include <vector>

class Interaction;

class Selection : public EventEmitter {
public:
  explicit Selection(Interaction* interaction) : interaction_(interaction) {
    bindEvents();
  };

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

  void bindEvents();
	void handleMouseMove(Event* event);
	void handleMouseDown(Event* event);

	void setSelection(const vector<Node*>& nodes);
  void setSelection(const vector<GUID>& nodesIds);

  void emitSelectionChange();
};
