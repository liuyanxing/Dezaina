#pragma once

#include "base/object.h"
#include "change/command.h"
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
  void addNodeChange(node::Node *node) {
    if (nodeChanges_.find(node) == nodeChanges_.end()) {
      auto *nodeChange = pool_.allocate<message::NodeChange>();
      nodeChange->set_guid(node->getGuid().toChange(pool_));
      nodeChanges_[node] = nodeChange;
    }
  }

  auto *getNodeChange(node::Node *node) {
    auto it = nodeChanges_.find(node);
    if (it != nodeChanges_.end()) {
      return it->second;
    }
    return static_cast<message::NodeChange *>(nullptr);
  }

  auto* getOrAddNodeChange(node::Node *node) {
    if (!getNodeChange(node)) {
      addNodeChange(node);
    }
    return getNodeChange(node);
  }

  void addChange(ChangeType type, ChangeValue &&value);
  auto &getPool() { return pool_; }
  void clear() {
    items_.clear();
    pool_.clear();
    nodeChanges_.clear();
  }
  void flush();

  void undo() { cmdManager_.undo(); }
  void redo() { cmdManager_.redo(); }

  message::Message saveBeforeChange();

private:
  std::vector<ChangeItem> items_;
  kiwi::MemoryPool pool_;
  NodeChanges nodeChanges_{};
  CommandManager cmdManager_;
};

} // namespace dea::change
