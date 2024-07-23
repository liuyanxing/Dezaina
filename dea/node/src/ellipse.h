#pragma once

#include "./node-base/node.h"

namespace dea::node {

class EllipseNode: public EllipseNodeBase {
public:
  static constexpr NodeType Type = NodeType::ELLIPSE;
	EllipseNode() {
		setType(Type);
	};
	~EllipseNode() = default;
};

} // namespace dea::node
