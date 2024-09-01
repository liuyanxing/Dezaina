#pragma once

#include "event.h"
#include "node.h"
#include "listener.h"


namespace dea::interaction {

class Creation : public InteractionListener {
public:
	Creation() {};

private:
	void onMouseDrag(event::MouseEvent& event) override;
	void onMouseUp(event::MouseEvent& event) override;
  node::Node* creatingNode_ = nullptr;
};

}