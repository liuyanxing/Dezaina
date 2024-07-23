#pragma once

#include "./node-base/node.h"

namespace dea::node {

class LineNode : public LineNodeBase {
public:
  static constexpr NodeType Type = NodeType::LINE;
};

} // namespace dea::node
