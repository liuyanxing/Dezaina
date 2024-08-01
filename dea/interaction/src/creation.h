#pragma once

#include "event_system/listener.h"


namespace interaction {

class Interaction;

class Creation : public Listener {
public:
	Creation(Interaction* interaction);
	~Creation() = default;

	void onMouseDrag(MouseEvent* event) override;
	void onMouseUp(MouseEvent* event) override;
private:
  Interaction* interaction_;
  Node* creating_node_ = nullptr;
};

}