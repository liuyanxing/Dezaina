#pragma once

#include "node_type.h"

class ChangeSystem;
class UpdatePropertiesAction;

namespace constraintLayout {
  void hanldeTransfrom(ChangeSystem* changeSystem, const UpdatePropertiesAction& action);
  void hanldeResize(ChangeSystem* changeSystem, const UpdatePropertiesAction& action);
  void hanldeResizeDelta(ChangeSystem* changeSystem, const UpdatePropertiesAction& action);
  bool processUpdatePropertiesAction(ChangeSystem* changeSystem, const UpdatePropertiesAction& action);
};
