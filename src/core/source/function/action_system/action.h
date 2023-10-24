#pragma once

#include "base_type.h"
enum class ActionType {
  kNone,
  kUpdateProperties,
};

struct Action {
  Action(ActionType type) : type(type) {};
  virtual ~Action() = default;
  const ActionType type;
};

using ActionPtr = shared_ptr<Action>;
  
