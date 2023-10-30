#pragma once

#include "action_system/action.h"
#include "base_type.h"
#include "event_system/event_system.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
#include "system/system.h"

using ActionPtr = shared_ptr<Action>;

class ActionSystem : public System {
 public:
  ActionSystem(Desaina*) {};
  ~ActionSystem() = default;
  void tick() override {};
  void addAction(ActionPtr&& action) { actions_.push_back(std::move(action)); };
  const vector<ActionPtr>& getActions() const { return actions_; };
  void clearActions() { actions_.clear(); };

  void rotate(float deltaRotation, const Node* node);
  void setRotate(float degrees, const Node* node);
  void translate(float deltaX, float deltaY, const Node* node);
  void setTranslate(float x, float y, const Node* node);
  void resize(float deltaWidth, float deltaHeight, const Node* node);
  void setSize(float width, float height, const Node* node);
  void setTransform(const SkMatrix& transform, const Node* node);

  void createNode(const Node* node, const Node* parent, const Node* before);
  
 private:
  vector<ActionPtr> actions_;
};
