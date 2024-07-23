#pragma once

#include "./node-base/node.h"

namespace dea::node {

class StarNode : public StarNodeBase {
public:
  static constexpr NodeType Type = NodeType::STAR;
};

} // namespace dea::node
