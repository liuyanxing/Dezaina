#pragma once

#include "node.h"

namespace dea::node {

class Container {
public:
  Node* firstChild() const {
    return firstChild_;
  };

  Node* removeChild(Node* node) {
    if (!node) {
      return nullptr;
    }
    if (node == firstChild_) {
      firstChild_ = node->getNextSibling();
      return firstChild_;
    }
    // find pre node
    Node* preNode = firstChild_;
    while (preNode && preNode->getNextSibling() != node) {
      preNode = preNode->getNextSibling();
    }
    if (preNode) {
      auto* next = node->getNextSibling();
      preNode->setNextSibling(next);
      return next;
    }
    return nullptr;
  }

  Node* findChild(Node* node) {
    if (!node) {
      return nullptr;
    }
    Node* current = firstChild_;
    while (current) {
      if (current == node) {
        return current;
      }
      current = current->getNextSibling();
    }
    return nullptr;
  }

  bool empty() const {
    return !firstChild_;
  };
	
  static bool append(Node* child, Node* parent);
protected:
	void appendChild(Node* node) {
    if (!lastChild_) {
      firstChild_ = node;
      lastChild_ = node;
      return;
    }
    lastChild_->setNextSibling(node);
    lastChild_ = node;
  };

 
  Node* firstChild_ = nullptr;
  Node* lastChild_ = nullptr;
};

} // namespace dea::node
