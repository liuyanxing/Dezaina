#pragma once

#include "node.h"

namespace dea::node {

class Container {
public:
  Node* firstChild() const {
    return firstChild_;
  };

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
  static void remove(Node* child, Node* parent);
protected:
  // becaue container cannot cast to node, we cannot set child's parent, so we cannot use appendChild directly
	void appendChild(Node* node) {
    if (!firstChild_) {
      firstChild_ = node;
      lastChild_ = node;
      return;
    }
    lastChild_->setNextSibling(node);
    lastChild_ = node;
  };

  struct ListNode {
    Node* node;
    Node* next;
  };

  void removeChild(Node* node) {
    if (!node) {
      return;
    }
    ListNode preNode = ListNode{nullptr, nullptr};
    preNode.next = firstChild_;
    while (preNode.next) {
      if (preNode.next == node) {
        if (preNode.node) {
          preNode.node->setNextSibling(node->getNextSibling());
          if (lastChild_ == node) {
            lastChild_ = preNode.node;
          }
        } else {
          firstChild_ = node->getNextSibling();
        }
        break;
      }
      preNode.node = preNode.next;
      preNode.next = preNode.next->getNextSibling();
    }
 }
 
  Node* firstChild_ = nullptr;
  Node* lastChild_ = nullptr;
};

} // namespace dea::node
