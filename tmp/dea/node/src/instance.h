#pragma once

#include "container.h"

namespace dea::node {

class InstanceNode : public InstanceNodeBase, public Container {
public:
	InstanceNode() {
		type = NodeType::INSTANCE;
	};
};

} // namespace dea::node