#pragma once

#include "./node-base/node.h"

namespace dea::node {

class RectangleNode: public RectangleNodeBase {
public:
  static constexpr NodeType Type = NodeType::RECTANGLE;
	RectangleNode() {
	  setType(Type);
	};
};

} // namespace dea::node