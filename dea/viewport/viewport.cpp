#include "viewport.h"

namespace dea {

void ViewPort::update(uint32_t width, uint32_t height, float devicePixelRatio) {
  width_ = width;
  height_ = height;
  devicePixelRatio_ = devicePixelRatio;
  float center_x = width_ * devicePixelRatio_ / 2.;
  float center_y = height_ * devicePixelRatio_ / 2.;
  projection_matrix_.reset();
  projection_matrix_.setTranslate(center_x, center_y);
  updateVPMatrix();

}

void ViewPort::translate(float dx, float dy) {
  view_matrix_.preTranslate(-dx, dy);
  updateVPMatrix();
}

} // namespace dea