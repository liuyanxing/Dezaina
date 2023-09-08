#include "change/change_type.h"
#include "desaina.h"
#include "change_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "util/node_geometry.h"
#include "util/node_create.h"
#include "util/node_props.h"

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
    if (layout->processUpdatePropertiesAction(action, change_pool_)) {
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
    if (!node.has_value() || changing_items_.find(id.value()) != changing_items_.end()) {
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
  for (auto& changeItemPair : changing_items_) {
    auto& guid = changeItemPair.first;
    auto& changeItem = changeItemPair.second;
    auto& changeNode = *changeItem.changeNode;
    auto node = desaina_->document.getNodeById(guid);
    if (!node.has_value()) {
      continue;
    }
    if (changeItem.isFillGeometryDirty) {
      auto* geometry = util::buildFillGeometry(changeItem.layoutNode, desaina_);
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
  change_processor_.processMessage(message);
  
  change_pool_.clear();
  node_pool_.clear();
  changing_items_.clear();
}

LayoutNode* ChangeSystem::appendLayoutNode(GUID guid) {
  auto node = desaina_->document.getNodeById(guid);
  if (!node.has_value()) {
    return nullptr;
  }
  layout_nodes_.push_back({});
  auto& layoutNode = layout_nodes_.back();
  layoutNode.node = node.value(); 
  layoutNode.size = util::getSize(node.value());
  layoutNode.transform = util::getTransfromMatrix(node.value());
  return &layoutNode;
}