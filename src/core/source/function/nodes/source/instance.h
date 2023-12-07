#pragma once

#include "container_node_base.h"

class InstanceNode : public InstanceNodeBase, public ContainerNodeBase {
public:
	InstanceNode() {
		set_type(NodeType::INSTANCE);
	};
};