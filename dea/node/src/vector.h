#pragma once

#include "./node-base/node.h"

namespace dea::node {

class VectorNode : public VectorNodeBase {
public:
	static constexpr NodeType Type = NodeType::VECTOR;
};

} // namespace dea::node