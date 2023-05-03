#pragma once

#include "desaina_node.h"

class FrameNode : public FrameNodeBase {
public:
	FrameNode() {
		set_type(NodeType::FRAME);
	};
};