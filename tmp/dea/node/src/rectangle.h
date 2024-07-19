#pragma once

#include "desaina_node.h"

namespace dea::node {

class RectangleNode: public RectangleNodeBase {
public:
	RectangleNode() {
		set_type(NodeType::RECTANGLE);
	};
};

} // namespace dea::node