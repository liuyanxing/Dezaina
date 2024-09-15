#pragma once

#include "base/object.h"
#include "node.h"
#include "schema/message.h"
#include "undoRedo.h"
#include <variant>
#include <vector>

namespace dea::change {

enum class ChangeType {
  Select,
  NodeChange,
};

using ChangeValue = std::variant<message::NodeChange *, node::NodeIdArray>;

struct ChangeItem {
  ChangeType type;
  ChangeValue value;
};

class Change : public base::NonCopyable {
public:
  bool addNodeChange(node::Node *node) {
    if (changeMap_.find(node) == changeMap_.end()) {
      auto *nodeChange = pool_.allocate<message::NodeChange>();
      nodeChange->set_guid(node->getGuid().toChange(pool_));
      changeMap_[node] = nodeChange;
      return true;
    }
    return false;
  }

  auto *getNodeChange(node::Node *node) {
    auto it = changeMap_.find(node);
    if (it != changeMap_.end()) {
      return it->second;
    }
    return static_cast<message::NodeChange *>(nullptr);
  }

  void addChange(ChangeType type, ChangeValue &&value);
  auto &getPool() { return pool_; }
  void clear() {
    items_.clear();
    pool_.clear();
    changeMap_.clear();
  }
  void flush();

private:
  std::vector<ChangeItem> items_;
  UndoRedo<ChangeItem> undoRedo_;
  kiwi::MemoryPool pool_;
  std::unordered_map<node::Node *, message::NodeChange *> changeMap_{};
};

} // namespace dea::change
