#pragma once

#include "action_system/UpdatePropertiesAction.h"
#include "action_system/action.h"
#include "action_system/action_system.h"
#include "base_type.h"
#include "change_system/change_processor.h"
#include "change_system/layouts/auto_layout.h"
#include "change_system/layouts/constraint_layout.h"
#include "change_system/layouts/layout.h"
#include "desaina_node.h"
#include "node_type.h"
#include "node_pool.h"
#include "system/system.h"
#include <memory>
#include <unordered_map>
#include <vector>
#include "layouts/layout_node.h"
#include "change_system/action_processor/update_properties_processor.h"
#include "change_system/action_processor/create_delete_processor.h"

using LayoutPtr = shared_ptr<Layout>;

struct ChangeItem {
  LayoutNode* layoutNode = nullptr;
  NodeChange* nodeChange = nullptr;
  bool isFillGeometryDirty;
  bool isStrokeGeometryDirty;
  
  static ChangeItem Make(LayoutNode* layoutNode, NodeChange* change_node) {
    return {layoutNode, change_node, false, false};
  }
};

class ChangeSystem : public System {
 public:
  ChangeSystem(Desaina* desaina) : desaina_(desaina) {
    action_procs_.push_back(std::make_shared<UpdatePropertiesActionProc>(this));
    action_procs_.push_back(std::make_shared<CreateDeleteActionProc>(this));
  };
  ~ChangeSystem() = default;

  unordered_map<GUID, ChangeItem>* getChangingItems() { return &changing_items_; }

  ChangeItem* getChangingItem(GUID guid) {
    auto it = changing_items_.find(guid);
    if (it == changing_items_.end()) {
      return nullptr;
    }
    return &it->second;
  }

  bool processMessage(kiwi::ByteBuffer& buffer) { return change_processor_.processMessage(buffer); }
  LayoutNode* appendLayoutNode(Node* node);
  void tick() override;

  kiwi::MemoryPool* pool() { return &change_pool_; }
  int addBlob(const Blob* blob);
  
 private:
  void addChangingItem(Action* action);
  void applyActions(const vector<ActionPtr>& actions);
  void processAction(const Action* action);
  void processAction(const UpdatePropertiesAction* action);
 
  Desaina* desaina_;
  vector<LayoutPtr> layouts;
  vector<LayoutNode> layout_nodes_;
 
  kiwi::MemoryPool change_pool_;
  NodePool node_pool_{10};
  unordered_map<GUID, ChangeItem> changing_items_;
  ChangeProcessor change_processor_{desaina_};
  vector<const Blob*> blobs_;
  vector<shared_ptr<ActionProc>> action_procs_;
};
