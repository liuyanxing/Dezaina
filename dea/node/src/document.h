#pragma once

#include "container.h"
#include "node-base/node.generated.h"

namespace dea::node {

class DocumentNode : public DocumentNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::DOCUMENT;
	DocumentNode() {
    setType(Type);
	};

};

} // namespace dea::node