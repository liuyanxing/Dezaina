#pragma once

#include "desaina_node.h"

class PageNode : public PageNodeBase {
public:
	PageNode() {
		set_type(NodeType::CANVAS);
	};
};
