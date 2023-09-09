#include "action_system/UpdatePropertiesAction.h"
#include "desaina.h"
#include "constraint_layout.h"

bool ConstraintLayout::processUpdatePropertiesAction(const UpdatePropertiesAction *action, kiwiPool &pool) {
  auto nodeOpt = desaina_->document.getNodeById(action->node_id);
  if (!nodeOpt.has_value()) {
    return true;
  }

  switch (action->propertyType) {
    case PropertyType::kTransform:
      hanldeTransfrom(action, pool);
      break;
    case PropertyType::kSize:
      hanldeResize(action, pool);
    case PropertyType::kResizeDelta:
      hanldeResizeDelta(action, pool);
      break;
    default:
      break;
  }
    
  return true;
}

void ConstraintLayout::hanldeTransfrom(const UpdatePropertiesAction *action, kiwiPool &pool) {
  auto changeItem = desaina_->changeSystem.getChangingItem(action->node_id);
  if (changeItem == nullptr) {
    return;
  }
  auto* changeNode = changeItem->changeNode;
  auto transform = get<Matrix>(action->propertyValue);
  changeNode->set_transform(transform.toChange(pool));
}

void ConstraintLayout::hanldeResize(const UpdatePropertiesAction *action, kiwiPool &pool) {
  auto changeItem = desaina_->changeSystem.getChangingItem(action->node_id);
  auto size = get<Vector>(action->propertyValue);
  auto* nodeChange = changeItem->changeNode;
  nodeChange->set_size(size.toChange(pool));
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}

void ConstraintLayout::hanldeResizeDelta(const UpdatePropertiesAction *action, kiwiPool &pool) {
  auto changeItem = desaina_->changeSystem.getChangingItem(action->node_id);
  if (changeItem->layoutNode == nullptr) {
    changeItem->layoutNode = desaina_->changeSystem.appendLayoutNode(action->node_id);
  }
  auto& layoutNode = changeItem->layoutNode;
  auto deltaSize = get<Vector>(action->propertyValue);
  layoutNode->size.x += deltaSize.x;
  layoutNode->size.y += deltaSize.y;

  auto* nodeChange = changeItem->changeNode;
  nodeChange->set_size(layoutNode->size.toChange(pool));
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}