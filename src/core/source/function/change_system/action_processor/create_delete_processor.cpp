#include "create_delete_processor.h"
#include "change_system/change_system.h"
#include "action_system/create_delete_action.h"
#include "desaina_node.h"
#include "util/skia.h"

void CreateDeleteActionProc::process(const Action* action) {
  auto create_delete_action = static_cast<const CreateDeleteAction*>(action);
  switch (create_delete_action->type) {
    case ActionType::kCreate:
      return processCreate(create_delete_action);
    case ActionType::kDelete:
      return processCreate(create_delete_action);
    default:
      break;
  }
}

void CreateDeleteActionProc::processCreate(const CreateDeleteAction* action) {
  auto node = action->node;
  auto before = action->before;
  auto* changeItem = change_system_->getChangingItem(node->get_guid());
  auto* defaultShapNode = static_cast<DefaultShapeNode*>(node);
  node->toChange(*changeItem->nodeChange, *(change_system_->pool()));
  
  changeItem->layoutNode->node = node;
  changeItem->layoutNode->size = defaultShapNode->get_size();
  changeItem->layoutNode->transform = util::toSkMatrix(defaultShapNode->get_transform());
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}

void CreateDeleteActionProc::processDelete(const CreateDeleteAction* action) {
}