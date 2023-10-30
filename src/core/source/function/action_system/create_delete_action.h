
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
  CreateDeleteAction(const Node* node, const Node* parent, const Node* before, ActionType actionType) : 
    node(node), parent(parent), before(before), Action(actionType) {};
  
  const Node* node;
  const Node* parent;
  const Node* before;

  static auto Make(const Node* node, const Node* parent, const Node* before, ActionType actionType) {
    auto action = make_shared<CreateDeleteAction>(node, parent, before, actionType);
    return action;
  }

  static auto MakeCreate(const Node* node, const Node* parent, const Node* before) {
    return Make(node, parent, before, ActionType::kCreate);
  }

  static auto MakeDelete(const Node* node) {
    return Make(node, nullptr, nullptr, ActionType::kDelete);
  }
};
