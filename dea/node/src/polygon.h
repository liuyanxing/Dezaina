#pragma once

#include "./node-base/node.h"

namespace dea::node {

class PolygonNode : public PolygonNodeBase {
public:
  static constexpr NodeType Type = NodeType::REGULAR_POLYGON;
};

} // namespace dea::node
