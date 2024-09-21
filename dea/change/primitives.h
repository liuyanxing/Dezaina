#pragma once

#include "schema/message.h"
#include <unordered_map>
#include "node.h"

namespace dea::change {

enum class ChangeType {
  Select,
  NodeChange,
};

using NodeChanges = std::unordered_map<node::NodePtr, message::NodeChange*>;

} // namespace dea::change