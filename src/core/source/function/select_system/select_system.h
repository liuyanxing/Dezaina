#pragram once

#include "event_system/event_system.h"
#include "system/system.h"

class SelectSystem : public System {
public:
	SelectSystem(Desaina* desaina) : desaina_(desaina) {}
	void tick() override {}
private:
	void buildEvents();
	Desaina* desaina_;
};