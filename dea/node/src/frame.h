#pragma once

#include "container.h"

namespace dea::node {

class FrameNode : public FrameNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::FRAME;
	FrameNode() {
	  setType(Type);
	};
};

} // namespace dea::node