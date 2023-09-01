#pragma once

enum class ActionType {
  kNone,
  kUpdateProperties,
};

struct Action {
  Action(ActionType type) : type(type) {};
  virtual ~Action() = default;
  const ActionType type;
};
  