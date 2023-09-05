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
