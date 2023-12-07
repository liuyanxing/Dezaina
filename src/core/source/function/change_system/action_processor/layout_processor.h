#pragma once
#include <unordered_set>
#include "action_system/UpdatePropertiesAction.h"
#include "change_system/layouts/constraint_layout.h"

void processAutoLayout(const UpdatePropertiesAction& action);

inline bool processLayout(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  static unordered_set<PropertyType> relatedProperties = {PropertyType::kResizeDelta, PropertyType::kRotation, PropertyType::kSize, PropertyType::kTransform};
  if (!relatedProperties.contains(action.propertyType)) {
    return false;
  }
  constraintLayout::processUpdatePropertiesAction(changeSystem, action);
  return true;
}
