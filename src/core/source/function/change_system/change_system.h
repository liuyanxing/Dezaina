#pragma once

#include "action_system/UpdatePropertiesAction.h"
#include "action_system/action.h"
#include "action_system/action_system.h"
#include "base_type.h"
#include "change_system/layouts/auto_layout.h"
#include "change_system/layouts/constraint_layout.h"
#include "change_system/layouts/layout.h"
#include "system/system.h"
#include <vector>

using LayoutPtr = shared_ptr<Layout>;

class ChangeSystem : public System {
 public:
  ChangeSystem(Desaina* desaina) : desaina_(desaina) {
    layouts.push_back(make_shared<AutoLayout>(desaina_));
    layouts.push_back(make_shared<ConstraintLayout>(desaina_));
  };
  ~ChangeSystem() = default;

  void tick() override;

  void convertActionsToChange(const vector<ActionPtr>& actions);
  void processAction(Action* action);
  void processAction(UpdatePropertiesAction* action);
  
 private:
  Desaina* desaina_;
  kiwi::MemoryPool pool;
  vector<Desaina_Kiwi::NodeChange*> node_changes_;
  vector<LayoutPtr> layouts;
};
