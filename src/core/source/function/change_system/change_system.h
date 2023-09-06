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
#include <unordered_map>
#include <vector>

using LayoutPtr = shared_ptr<Layout>;

struct ChangeItem {
  Node* node = nullptr;
  NodeChange* changeNode = nullptr;
  bool isFillGeometryDirty;
  bool isStrokeGeometryDirty;
  
  static ChangeItem Make(Node* node, NodeChange* change_node) {
    return {node, change_node, false, false};
  }
};

class ChangeSystem : public System {
 public:
  ChangeSystem(Desaina* desaina) : desaina_(desaina) {
    layouts.push_back(make_shared<AutoLayout>(desaina_));
    layouts.push_back(make_shared<ConstraintLayout>(desaina_));
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

  void tick() override;
  
 private:
  void addChangingItem(const Action* action);
  void convertActionsToChange(const vector<ActionPtr>& actions);
  void processAction(const Action* action);
  void processAction(const UpdatePropertiesAction* action);

 
  Desaina* desaina_;
  vector<LayoutPtr> layouts;
 
  kiwi::MemoryPool change_pool_;
  NodePool node_pool_{10};
  unordered_map<GUID, ChangeItem> changing_items_;
  ChangeProcessor change_processor_{desaina_};
};
