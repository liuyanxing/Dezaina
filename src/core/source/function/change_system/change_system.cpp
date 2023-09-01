#include "change_system.h"
#include "action_system/UpdatePropertiesAction.h"

void ChangeSystem::convertActionsToChange() {
  auto& actions = desaina_->actionSystem.getActions();
}

void ChangeSystem::processAction(Action *action) {
  switch (action->type) {
    case ActionType::kUpdateProperties:
      processAction(static_cast<UpdatePropertiesAction*>(action));
      break;
    default:
      break;
  }
}

void ChangeSystem::processAction(UpdatePropertiesAction *action) {
  for (auto& layout : layouts) {
    if (layout->processUpdatePropertiesAction(action, changes, pool)) {
      break;
    }
  }
}
