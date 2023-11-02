#pragma once

#include "action_system/action.h"
#include "base_type.h"

class ChangeSystem;

class ActionProc {
public:
  ActionProc(ChangeSystem* change_system) : change_system_(change_system) {};
  virtual void process(const Action* action) = 0;
  virtual bool shouldProcess(const Action* action) {
    return action_types_.find(action->type) != action_types_.end();
  }

protected:
  unordered_set<ActionType> action_types_;
  ChangeSystem* change_system_;
};