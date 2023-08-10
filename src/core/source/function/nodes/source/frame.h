#pragma once

#include "container_node_base.h"

class FrameNode : public FrameNodeBase, public ContainerNodeBase {
public:
	FrameNode() {
		set_type(NodeType::FRAME);
	};
};