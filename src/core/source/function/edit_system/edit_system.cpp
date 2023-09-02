#include "edit_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "util/node_props.h"
#include "desaina.h"
#include <iostream>

void EditSystem::bindEvents() {
  addEventListener(EventType::kMouseDrag, [this](Event* event) {
    handleMouseDrag(event);
  });
}

void EditSystem::handleMouseDrag(Event *event) {
  auto& actionSystem = desaina_->actionSystem;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;
  auto selectedNodes = desaina_->document.getSelectedNodes();
  if (selectedNodes.size() == 0) {
    return;
  }

  for (auto node : selectedNodes) {
    auto m = util::getTransfromMatrix(node);
    m.preTranslate(deltaX, deltaY);
    PropertyType type = PropertyType::kTransform;
    PropertyValue transform = util::toMatrix(m);
    
    actionSystem.addAction(UpdatePropertiesAction::Make(node->get_guid(), type, transform));
  }
}
