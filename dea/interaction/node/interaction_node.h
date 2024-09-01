#pragma once


#include "document.h"

namespace dea::interaction {

class InteractionNode {
public:
  void setParent(node::Node* parent) {
    parent_ = parent;
  }
  node::Node* getParent() { return parent_; }
  
private:
  node::Node* parent_ = nullptr;
};

}
