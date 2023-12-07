#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "event_system/mouse_event.h"
#include "node_type.h"
#include "system/system.h"
#include <string>
#include "desaina.h"

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

  template<typename T>
  void startCreating() {
    // todo: check if creating_node_ is nullptr if not nullptr, delete it
    if (creating_node_ != nullptr) {
    }
    creating_node_ = desaina_->document.createNode<T>();
  };
  
 private:
  void handleMouseDrag(MouseEvent* event);
  Desaina* desaina_;
  Node* creating_node_ = nullptr;
};
