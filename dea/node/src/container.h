#pragma once

#include "./node-base/node.h"
#include "node/src/node-base/node.h"
#include "./node-base/type.generated.h"

namespace dea::node {

class Container {
public:
	void appendChild(Node* node) {
    if (!lastChild_) {
      firstChild_ = node;
      lastChild_ = node;
      return;
    }
    lastChild_->setNextSibling(node);
    lastChild_ = node;
  };

  Node* firstChild() const {
    return firstChild_;
  };

  bool empty() const {
    return !firstChild_;
  };
	
  static void append(Node* parent, Node* child) {
    if (!parent) {
      return;
    }
    auto container = node_cast<Container*>(parent);
    if (container) {
      container->appendChild(child);
    }
  };
protected:
  Node* firstChild_ = nullptr;
  Node* lastChild_ = nullptr;
};

} // namespace dea::node
