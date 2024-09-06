#include "viewport.h"

namespace dea {

void Viewport::reset() {
  update(width_, height_, devicePixelRatio_);
}

void Viewport::update(uint32_t width, uint32_t height, float devicePixelRatio) {
  width_ = width;
  height_ = height;
  devicePixelRatio_ = devicePixelRatio;
  float center_x = width_ * devicePixelRatio_ / 2.;
  float center_y = height_ * devicePixelRatio_ / 2.;
  projectionMatrix_.reset();
  projectionMatrix_.setTranslate(center_x, center_y);
  updateVPMatrix();

}

void Viewport::translate(float dx, float dy) {
  viewMatrix_.preTranslate(-dx, dy);
  updateVPMatrix();
}

void Viewport::scale(float sx, float sy, float px, float py) {
  viewMatrix_.preScale(sx, sy, px, py);
  updateVPMatrix();
}

} // namespace dea