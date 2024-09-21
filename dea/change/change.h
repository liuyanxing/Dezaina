#pragma once

#include "base/object.h"
#include "node.h"
#include "schema/message.h"
#include <variant>
#include <vector>
#include "primitives.h"

namespace dea::change {

using ChangeValue = std::variant<message::NodeChange *, node::NodeIdArray>;

struct ChangeItem {
  ChangeType type;
  ChangeValue value;
};

class Change : public base::NonCopyable {
public:
  bool addNodeChange(node::Node *node) {
    if (nodeChangesMap_.find(node) == nodeChangesMap_.end()) {
      auto *nodeChange = pool_.allocate<message::NodeChange>();
      nodeChange->set_guid(node->getGuid().toChange(pool_));
      nodeChangesMap_[node] = nodeChange;
      return true;
    }
    return false;
  }

  auto *getNodeChange(node::Node *node) {
    auto it = nodeChangesMap_.find(node);
    if (it != nodeChangesMap_.end()) {
      return it->second;
    }
    return static_cast<message::NodeChange *>(nullptr);
  }

  void addChange(ChangeType type, ChangeValue &&value);
  auto &getPool() { return pool_; }
  void clear() {
    items_.clear();
    pool_.clear();
    nodeChangesMap_.clear();
  }
  void flush();

  message::Message saveBeforeChange();

private:
  std::vector<ChangeItem> items_;
  kiwi::MemoryPool pool_;
  std::unordered_map<node::Node *, message::NodeChange *> nodeChangesMap_{};
};

} // namespace dea::change
