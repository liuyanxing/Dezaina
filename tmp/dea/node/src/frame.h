#pragma once

#include "container.h"

namespace dea::node {

class FrameNode : public FrameNodeBase, public Container {
public:
	FrameNode() {
		type = NodeType::FRAME;
	};
};

} // namespace dea::node