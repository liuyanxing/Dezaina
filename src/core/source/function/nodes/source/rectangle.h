#pragma once

#include "desaina_node.h"

class RectangleNode: public RectangleNodeBase {
public:
	RectangleNode() {
		set_type(NodeType::RECTANGLE);
	};
};