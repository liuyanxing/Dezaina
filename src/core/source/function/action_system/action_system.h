#pragma once

#include "action_system/UpdatePropertiesAction.h"
#include "action_system/action.h"
#include "base_type.h"
#include "event_system/event_system.h"
#include "include/core/SkMatrix.h"
#include "node_type.h"
#include "system/system.h"

class ActionSystem : public System {
 public:
  ActionSystem(Desaina*) {};
  ~ActionSystem() = default;
  void tick() override {};
  void addAction(ActionPtr&& action) { actions_.push_back(std::move(action)); };
  const vector<ActionPtr>& getActions() const { return actions_; };
  void clearActions() { actions_.clear(); };

  void updateProperty(const PropertyType& propertyType, const PropertyValue&& propertyValue, const Node* node);
  void rotate(float deltaRotation, const Node* node);
  void setRotate(float degrees, const Node* node);
  void translate(float deltaX, float deltaY, const Node* node);
  void setTranslate(float x, float y, const Node* node);
  void resize(float deltaWidth, float deltaHeight, const Node* node);
  void setSize(float width, float height, const Node* node);
  void setTransform(const SkMatrix& transform, const Node* node);

  void createNode(Node* node, Node* before);
  
 private:
  vector<ActionPtr> actions_;
};
