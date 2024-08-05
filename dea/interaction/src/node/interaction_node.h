#pragma once


#include "document.h"
namespace dea::interaction {

class InteractionNode {
public:
  bool isActiveByPixel() const { return is_active_by_pixel_; }
  void setActiveByPixel(bool active) { is_active_by_pixel_ = active; }
  void setParent(node::Node* parent) { parent_ = parent; }
  node::Node* getParent() { return parent_; }
  
private:
  // if not active by pixel, it is active by bound
  bool is_active_by_pixel_ = true;
  node::Node* parent_ = nullptr;
};

}
