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
  vector<Node* > getHoverNodes() const;
private:
	void buildEvents();
	vector<Node*> hover_nodes_;
	Desaina* desaina_;
};
