#pragma once

#include "container_node_base.h"

class PageNode : public PageNodeBase, public ContainerNodeBase {
public:
	PageNode() {
		set_type(NodeType::CANVAS);
	};
};
