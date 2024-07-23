#pragma once

#include "./node-base/node.h"

namespace dea::node {

class TextNode : public TextNodeBase {
public:
  static constexpr NodeType Type = NodeType::TEXT;
};

} // namespace dea::node
