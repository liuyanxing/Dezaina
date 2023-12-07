#pragma once

#include "action_processor.h"
#include "action_system/action.h"
#include "action_system/create_delete_action.h"

class ChangeSystem;

class CreateDeleteActionProc : public ActionProc {
public:
  CreateDeleteActionProc(ChangeSystem* change_system) : ActionProc(change_system) {
    action_types_.insert(ActionType::kCreate);
  };

  void process(const Action* action) override;
private:
  void processCreate(const CreateDeleteAction* action);
  void processDelete(const CreateDeleteAction* action);
};