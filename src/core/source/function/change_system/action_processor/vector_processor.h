#pragma once
#include "action_system/UpdatePropertiesAction.h"
class ChangeSystem;

void processVectorData(ChangeSystem* changeSystem, const UpdatePropertiesAction& action);
bool processVector(ChangeSystem* change_system, const UpdatePropertiesAction& action);
