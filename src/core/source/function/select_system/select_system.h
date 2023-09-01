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
  Node* getHoverNode() const;
  vector<Node*> getSelectedNodes() const;
	
private:
	void buildEvents();
	void handleMouseMove(Event* event);
	void handleMouseDown(Event* event);
  vector<GUID> selected_node_id_{};
  std::optional<GUID> hovered_node_id_ = std::nullopt;
	Desaina* desaina_;
};
