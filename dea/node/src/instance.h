#pragma once

#include "container.h"

namespace dea::node {

class InstanceNode : public InstanceNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::INSTANCE;
	InstanceNode() {
	  setType(Type);
	};
};

} // namespace dea::node