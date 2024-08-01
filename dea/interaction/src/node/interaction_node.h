#pragma once

class InteractionNode {
public:
  bool isActiveByPixel() const { return is_active_by_pixel_; }
  void setActiveByPixel(bool active) { is_active_by_pixel_ = active; }
private:
  // if not active by pixel, it is active by bound
  bool is_active_by_pixel_ = true;
};
