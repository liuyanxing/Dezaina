#pragma once
#include "action_system/UpdatePropertiesAction.h"
#include <unordered_set>

void processConstraint(const UpdatePropertiesAction& action);

void processAutoLayout(const UpdatePropertiesAction& action);

inline bool processLayout(const UpdatePropertiesAction& action) {
  static unordered_set<PropertyType> relatedProperties = {};
  if (!relatedProperties.contains(action.propertyType)) {
    return false;
  }
  processConstraint(action);
  return true;
}
