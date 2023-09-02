#pragma once

#include "action_system/action.h"
#include "base_type.h"
#include "system/system.h"

using ActionPtr = shared_ptr<Action>;

class ActionSystem : public System {
 public:
  ActionSystem() {};
  ~ActionSystem() = default;
  void tick() override {};
  void addAction(ActionPtr&& action) { actions_.push_back(std::move(action)); };
  const vector<ActionPtr>& getActions() const { return actions_; };
  void clearActions() { actions_.clear(); };
  
 private:
  vector<ActionPtr> actions_;
};
