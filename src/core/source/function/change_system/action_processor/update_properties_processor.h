#include "action_processor.h"
#include "action_system/UpdatePropertiesAction.h"
#include "action_system/action.h"
#include <functional>
#include <unordered_set>
#include "vector_processor.h"
#include "layout_processor.h"

class ChangeSystem;

class UpdatePropertiesActionProc : public ActionProc {
public:
  UpdatePropertiesActionProc(ChangeSystem* change_system) : ActionProc(change_system) {
    action_types_ = { ActionType::kUpdateProperties };
    processors_.push_back(processVector);
    // processors_.push_back(processLayout);
  };

  void process(const Action* action) override {
    if (!shouldProcess(action)) {
      return;
    }
    for (auto& porc : processors_) {
      if (porc(change_system_, *static_cast<const UpdatePropertiesAction*>(action))) {
        break;
      }
    }
  }

private:
  vector<std::function<bool(ChangeSystem* changeSystem, const UpdatePropertiesAction&)> > processors_;
};