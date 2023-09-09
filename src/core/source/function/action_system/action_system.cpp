#include "action_system.h"
#include "UpdatePropertiesAction.h"

void ActionSystem::rotate(float deltaRotation, const Node* node) {
  auto rotation = util::getRotation(node);
  rotation += deltaRotation;
  setRotate(rotation, node);
}

void ActionSystem::setRotate(float degrees, const Node* node) {
  addAction(UpdatePropertiesAction::MakeSetRotate(degrees, node));
}

void ActionSystem::translate(float deltaX, float deltaY, const Node* node) {
  auto m = util::getTransfromMatrix(node);
  m.preTranslate(deltaX, deltaY);
  setTranslate(m.getTranslateX(), m.getTranslateY(), node);
}

void ActionSystem::setTranslate(float x, float y, const Node* node) {
  addAction(UpdatePropertiesAction::MakeSetTranslate(x, y, node));
}

void ActionSystem::resize(float deltaWidth, float deltaHeight, const Node* node) {
  auto size = util::getSize(node);
  setSize(size.x + deltaWidth, size.y + deltaHeight, node);
}

void ActionSystem::setSize(float width, float height, const Node* node) {
  addAction(UpdatePropertiesAction::MakeSetSize(width, height, node));
}
