#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "event_system/event_system.h"
#include "system/system.h"

class SelectSystem : public System {
public:
	SelectSystem(Desaina* desaina) : desaina_(desaina) {
    buildEvents();
  }
	void tick() override {}
	
private:
	void buildEvents();
	void handleMouseMove(Event* event);
	void handleMouseDown(Event* event);
	Desaina* desaina_;
};
