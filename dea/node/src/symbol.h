#pragma once

#include "container.h"

namespace dea::node {

class SymbolNode : public SymbolNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::SYMBOL;
	SymbolNode() {
		setType(Type);
	};
};

} // namespace dea::node
