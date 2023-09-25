#pragma once

#include "container_node_base.h"

class SymbolNode : public SymbolNodeBase, public ContainerNodeBase {
public:
	SymbolNode() {
		set_type(NodeType::SYMBOL);
	};
};