#pragma once

#include "container.h"

namespace dea::node {

class SymbolNode : public SymbolNodeBase, public Container {
public:
	SymbolNode() {
		set_type(NodeType::SYMBOL);
	};
};

} // namespace dea::node
