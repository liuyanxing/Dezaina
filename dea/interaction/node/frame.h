#pragma once

#include "node.h"
#include "interaction_node.h"


namespace dea::interaction {
class Frame : public node::FrameNode, public InteractionNode {
public:
	Frame() {
	}
	~Frame() = default;
};

}
