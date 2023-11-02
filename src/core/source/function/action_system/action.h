#pragma once

#include "base_type.h"
#include "node_type.h"
enum class ActionType {
  kNone,
  kUpdateProperties,
  kCreate,
  kDelete,
};

struct Action {
  Action(ActionType type, Node* n = nullptr) : type(type), node(n) {};
  virtual ~Action() = default;
  const ActionType type;
  Node* node = nullptr;
};

using ActionPtr = shared_ptr<Action>;
  
