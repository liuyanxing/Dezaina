#pragma once

#include "base_type.h"
#include "event_system/event_system.h"
#include "system/system.h"

class SelectSystem : public System {
public:
	SelectSystem(Desaina* desaina) : desaina_(desaina) {
    buildEvents();
  }
	void tick() override {}
  Node* getHoverNode() const;
private:
	void buildEvents();
	Node* hover_node_ = nullptr;
	Desaina* desaina_;
};
