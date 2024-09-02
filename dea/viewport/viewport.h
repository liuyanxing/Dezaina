#pragma once

#include <cmath>
#include <cstdint>
#include "event.h"
#include "node/node_base.generated.h"

namespace dea {
class Viewport : public event::EventEmitter {
public:
  Viewport() {};

  void update(uint32_t width, uint32_t height, float devicePixelRatio);

  void translate(float dx, float dy);
  void scale(float sx, float sy, float px = 0, float py = 0);

  const auto& getVPMatrix() const {
    return viewProjectionMatrix_;
  }

  const auto& getViewMatrix() {
    return viewMatrix_;
  }

  const auto& getProjectionMatrix() const {
    return projectionMatrix_;
  }

  const auto getViewScale()  const {
    return viewMatrix_.getScaleX();
  }

  void setProjectionMatrix(const SkMatrix& matrix) {
    projectionMatrix_ = matrix;
    updateVPMatrix();
  }

  void setViewMatrix(const SkMatrix& matrix) {
    viewMatrix_ = matrix;
    updateVPMatrix();
  }

  void updateVPMatrix() {
    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_ ;
    auto e = event::Event{};
    e.type = event::EventType::ViewportChange;
    emit(e);
  }

  auto mapWorldToScreen(const node::Rect& rect) {
    return viewProjectionMatrix_.mapRect(rect);
  }

  auto mapWorldToScreen(const node::Vector& point) {
    return viewProjectionMatrix_.mapPoint(point);
  }

  float mapWorldToScreen(float length) {
  }

  node::Vector mapScreenToWorld(float x, float y) {
    
  }

  float mapScreenToWorld(float length) {
    SkRect rect = SkRect::MakeWH(length, 0);
    SkMatrix inverse;
    if (viewProjectionMatrix_.invert(&inverse)) {
      return std::copysign(inverse.mapRect(rect).width(), length);
    }
    return inverse.getMaxScale() * length;
  }

  auto width() const { return width_; }
  auto height() const { return height_; }
  auto devicePixelRatio()  const { return devicePixelRatio_; }

private:
	node::Matrix viewMatrix_;
	node::Matrix projectionMatrix_;
  node::Matrix viewProjectionMatrix_;
  uint32_t width_ = 800;
  uint32_t height_ = 600;
  float devicePixelRatio_ = 1;
};
}
