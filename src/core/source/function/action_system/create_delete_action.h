
#pragma once

#include "action.h"
#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
#include "util/node_props.h"
#include "util/skia.h"
#include "util/node_geometry.h"

struct CreateDeleteAction : public Action {
  CreateDeleteAction(Node* n, Node* b, ActionType actionType) : 
    node(n), before(b), Action(actionType, n) {};
  
  Node* node;
  Node* before;

  static auto Make(Node* node, Node* before, ActionType actionType) {
    auto action = make_shared<CreateDeleteAction>(node, before, actionType);
    return action;
  }

  static auto MakeCreate(Node* node, Node* before) {
    return Make(node, before, ActionType::kCreate);
  }

  static auto MakeDelete(Node* node) {
    return Make(node, nullptr, ActionType::kDelete);
  }
};
