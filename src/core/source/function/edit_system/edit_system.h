#pragma once

#include "base_type.h"
#include "system/system.h"
#include <vector>

class Desaina;

class EditSystem : public System {
 public:
  EditSystem(Desaina* desaina) : desaina_(desaina) {
    bindEvents();
  };
  ~EditSystem() = default;

  void bindEvents();
  void handleMouseDrag(Event* event);
  
 private:
  Desaina* desaina_;
};
