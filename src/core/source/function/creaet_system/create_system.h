#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "event_system/mouse_event.h"
#include "node_type.h"
#include "system/system.h"
#include <string>

class Desaina;

class CreateSystem : public System {
 public:
  CreateSystem(Desaina* desaina) : desaina_(desaina) {
    init();
  };
  ~CreateSystem() = default;

  void tick() override {};

  void init();
  void bindEvents();

  void startCreating() {};
  
 private:
  void handleMouseDrag(MouseEvent* event);
  Desaina* desaina_;
  shared_ptr<Node> creating_node_type_;
};
