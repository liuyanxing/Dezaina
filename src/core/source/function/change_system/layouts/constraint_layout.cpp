#include "action_system/UpdatePropertiesAction.h"
#include "desaina.h"
#include "constraint_layout.h"
#include "change_system/change_system.h"

namespace constraintLayout {
bool processUpdatePropertiesAction(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  auto nodeOpt = changeSystem->desaina->document.getNodeById(action.node_id);
  if (!nodeOpt.has_value()) {
    return true;
  }

  switch (action.propertyType) {
    case PropertyType::kTransform:
      hanldeTransfrom(changeSystem, action);
      break;
    case PropertyType::kSize:
      hanldeResize(changeSystem, action);
      break;
    case PropertyType::kResizeDelta:
      hanldeResizeDelta(changeSystem, action);
      break;
    default:
      break;
  }
    
  return true;
}

void hanldeTransfrom(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  auto pool = changeSystem->pool();
  auto changeItem = changeSystem->getChangingItem(action.node_id);
  auto* nodeChange = changeItem->nodeChange;
  auto transform = get<Matrix>(action.propertyValue);
  nodeChange->set_transform(transform.toChange(*pool));
}

void hanldeResize(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  auto pool = changeSystem->pool();
  auto changeItem = changeSystem->getChangingItem(action.node_id);
  auto size = get<Vector>(action.propertyValue);
  auto& layoutNode = changeItem->layoutNode;
  layoutNode->size = size;

  auto* nodeChange = changeItem->nodeChange;
  nodeChange->set_size(size.toChange(*pool));
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}

void hanldeResizeDelta(ChangeSystem* changeSystem, const UpdatePropertiesAction& action) {
  auto pool = changeSystem->pool();
  auto changeItem = changeSystem->getChangingItem(action.node_id);
  auto& layoutNode = changeItem->layoutNode;
  auto deltaSize = get<Vector>(action.propertyValue);
  layoutNode->size.x += deltaSize.x;
  layoutNode->size.y += deltaSize.y;

  auto* nodeChange = changeItem->nodeChange;
  nodeChange->set_size(layoutNode->size.toChange(*pool));
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}
}
