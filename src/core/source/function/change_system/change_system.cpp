#include "change/change_type.h"
#include "desaina.h"
#include "change_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "util/node_geometry.h"

void ChangeSystem::convertActionsToChange(const vector<ActionPtr>& actions) {
  for (auto& action : actions) {
    addChangingItem(action.get());
    processAction(action.get());
  }
  desaina_->actionSystem.clearActions();
}

void ChangeSystem::processAction(const Action *action) {
  switch (action->type) {
    case ActionType::kUpdateProperties:
      processAction(static_cast<const UpdatePropertiesAction*>(action));
      break;
    default:
      break;
  }
}

void ChangeSystem::processAction(const UpdatePropertiesAction *action) {
  for (auto& layout : layouts) {
    if (layout->processUpdatePropertiesAction(action, node_changes_, change_pool_)) {
      break;
    }
  }
}

void ChangeSystem::addChangingItem(const Action *action) {
  std::optional<GUID> id;
  switch (action->type) {
    case ActionType::kUpdateProperties:
      id = static_cast<const UpdatePropertiesAction*>(action)->node_id;
      break;
    default:
      break;
  }
  if (id.has_value()) {
    auto& nodeId = id.value();
    auto node = desaina_->document.getNodeById(nodeId);
    if (!node.has_value()) {
      return;
    }
    auto* changeNode = change_pool_.allocate<Desaina_Kiwi::NodeChange>();
    changeNode->set_guid(nodeId.toChange(change_pool_));
    
    changing_items_[id.value()] = ChangeItem::Make(nullptr, changeNode);
  }
}

void ChangeSystem::tick() {
  const auto& actions = desaina_->actionSystem.getActions();
  if (actions.empty()) {
    return;
  }
  convertActionsToChange(actions);
  Desaina_Kiwi::Message message;
  message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
  auto& nodeChanges = message.set_nodeChanges(change_pool_, changing_items_.size());
  int index = 0;
  vector<const Blob*> blobs;
  uint32_t blobIndex = 0;
  message.set_blobs(change_pool_, 2);
  for (auto& changeItemPair : changing_items_) {
    auto& guid = changeItemPair.first;
    auto& changeItem = changeItemPair.second;
    auto& changeNode = *changeItem.changeNode;
    auto node = desaina_->document.getNodeById(guid);
    if (!node.has_value()) {
      continue;
    }
    if (changeItem.isFillGeometryDirty) {
      changeItem.node =  node.value().cloneBase(node_pool_);
      changeItem.node->applyChange(changeNode);
      auto* geometry = util::buildFillGeometry(changeItem.node, desaina_);
      changeNode.set_fillGeometry(change_pool_, 1)[0].set_commandsBlob(blobIndex++);
      blobs.push_back(geometry->commandsBlob);
    }
    if (changeItem.isStrokeGeometryDirty) {
    }
    nodeChanges[index++] = changeNode;
  }
  auto blobChanges = message.set_blobs(change_pool_, blobs.size());
  for (int i = 0; i < blobs.size(); ++i) {
    auto& blob = blobs[i];
    auto& blobChange = blobChanges[i];
    auto& blobChangeBuffer = blobChange.set_bytes(change_pool_, blob->size());
    blobChangeBuffer.set(blob->data(), blob->size());
  }
  desaina_->processMessage(message);
  
  change_pool_.clear();
  node_pool_.clear();
  changing_items_.clear();
}

