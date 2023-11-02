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
  // todo implement node->toChange
  // node->toChange()
  auto* defaultShapNode = static_cast<DefaultShapeNode*>(node);
  
  changeItem->nodeChange->set_size(defaultShapNode->get_size().toChange(*change_system_->pool()));
  changeItem->nodeChange->set_parentIndex(node->get_parentIndex().toChange(*change_system_->pool()));
  changeItem->nodeChange->set_type(Desaina_Kiwi::NodeType::ROUNDED_RECTANGLE);
  auto& paints = changeItem->nodeChange->set_fillPaints(*change_system_->pool(), 1);
  paints[0].set_type(Desaina_Kiwi::PaintType::SOLID);
  auto* color = change_system_->pool()->allocate<Desaina_Kiwi::Color>();
  color->set_a(1);
  color->set_r(1);
  color->set_g(0);
  color->set_b(0);
  paints[0].set_color(color);
  changeItem->layoutNode->node = node;
  changeItem->layoutNode->size = defaultShapNode->get_size();
  changeItem->layoutNode->transform = util::toSkMatrix(defaultShapNode->get_transform());
  changeItem->isFillGeometryDirty = true;
  changeItem->isStrokeGeometryDirty = true;
}

void CreateDeleteActionProc::processDelete(const CreateDeleteAction* action) {
}