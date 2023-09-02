#include "change_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "desaina.h"

void ChangeSystem::convertActionsToChange(const vector<ActionPtr>& actions) {
  for (auto& action : actions) {
    processAction(action.get());
  }
  desaina_->actionSystem.clearActions();
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
    if (layout->processUpdatePropertiesAction(action, node_changes_, pool)) {
      break;
    }
  }
}

void ChangeSystem::tick() {
  const auto& actions = desaina_->actionSystem.getActions();
  if (actions.empty()) {
    return;
  }
  convertActionsToChange(actions);
  Desaina_Kiwi::Message message;
  message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
  auto& nodeChanges = message.set_nodeChanges(pool, node_changes_.size());
  for (int i = 0; i < node_changes_.size(); i++) {
    nodeChanges[i] = *node_changes_[i];
  }
  desaina_->processMessage(message);
  node_changes_.clear();
}

