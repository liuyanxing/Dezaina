#pragma once

#include "listener.h"


namespace dea::interaction {

class Interaction;

class Creation : public InListener {
public:
	Creation(Interaction& interaction);
	~Creation() = default;

	void onMouseDrag(MouseEvent* event) override;
	void onMouseUp(MouseEvent* event) override;
private:
  Interaction& interaction_;
  Node* creating_node_ = nullptr;
};

}