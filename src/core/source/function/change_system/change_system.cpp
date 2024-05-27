#include "change/change_type.h"
#include "desaina.h"
#include "change_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "util/node_geometry.h"
#include "util/node_create.h"
#include "util/node_props.h"

void ChangeSystem::applyEditRecords(const vector<ActionPtr>& actions) {
  for (auto& action : actions) {
    addChangingItem(action.get());
    processAction(action.get());
  }
  desaina->actionSystem->clearActions();
}

void ChangeSystem::processAction(const Action *action) {
  for (auto& proc : action_procs_) {
    proc->process(action);
  }
}

void ChangeSystem::addChangingItem(Action *action) {
  std::optional<GUID> id;
  switch (action->type) {
    case ActionType::kUpdateProperties:
      id = static_cast<const UpdatePropertiesAction*>(action)->node_id;
      break;
    default:
      break;
  }
  if (action->node != nullptr) {
    id = action->node->get_guid();
  } else {
    action->node = desaina->document.getNodeById(id.value()).value();
  }
  if (id.has_value()) {
    auto& nodeId = id.value();
    auto node = desaina->document.getNodeById(nodeId);
    if (changing_items_.find(id.value()) != changing_items_.end()) {
      return;
    }
    auto* changeNode = change_pool_.allocate<Desaina_Kiwi::NodeChange>();
    changeNode->set_guid(nodeId.toChange(change_pool_));
    
    changing_items_[id.value()] = ChangeItem::Make(appendLayoutNode(action->node), changeNode);
  }
}

int ChangeSystem::addBlob(const Blob* blob) {
  blobs_.push_back(blob);
  return blobs_.size() - 1;
}

void ChangeSystem::tick() {
  const auto& actions = desaina->actionSystem->getActions();
  if (actions.empty()) {
    return;
  }
  applyEditRecords(actions);
  Desaina_Kiwi::Message message;
  message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
  auto& nodeChanges = message.set_nodeChanges(change_pool_, changing_items_.size());
  int index = 0;
  for (auto& changeItemPair : changing_items_) {
    auto& guid = changeItemPair.first;
    auto& changeItem = changeItemPair.second;
    auto& changeNode = *changeItem.nodeChange;
    auto node = desaina->document.getNodeById(guid);
    if (changeItem.isFillGeometryDirty) {
      auto blobPair = util::buildFillGeometry(changeItem.layoutNode, desaina);
      int blobIndex = addBlob(blobPair.second);
      changeNode.set_fillGeometry(change_pool_, 1)[0].set_commandsBlob(blobIndex);
    }
    if (changeItem.isStrokeGeometryDirty) {
    }
    nodeChanges[index++] = changeNode;
  }
  auto blobChanges = message.set_blobs(change_pool_, blobs_.size());
  for (int i = 0; i < blobs_.size(); ++i) {
    auto& blob = blobs_[i];
    auto& blobChange = blobChanges[i];
    auto& blobChangeBuffer = blobChange.set_bytes(change_pool_, blob->size());
    blobChangeBuffer.set(blob->data(), blob->size());
  }
  change_processor_.processMessage(message);
  
  change_pool_.clear();
  node_pool_.clear();
  changing_items_.clear();
  blobs_.clear();
}

LayoutNode* ChangeSystem::appendLayoutNode(Node* node) {
  if (!node) {
    return nullptr;
  }
  layout_nodes_.push_back({});
  auto& layoutNode = layout_nodes_.back();
  layoutNode.node = node; 
  layoutNode.size = util::getSize(node);
  layoutNode.transform = util::getTransfromMatrix(node);
  return &layoutNode;
}
