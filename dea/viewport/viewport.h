#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include <cstdint>
#include "event.h"

namespace dea {
class Viewport : public event::EventEmitter<>{
public:
  Viewport() {};

  void update(uint32_t width, uint32_t height, float devicePixelRatio);

  void translate(float dx, float dy);
  void scale(float sx, float sy, float px = 0, float py = 0);

  const auto& VPMatrix() {
    return viewProjectionMatrix_;
  }

  const auto& projectionMatrix() const {
    return projectionMatrix_;
  }

  const auto getScreenMatrix() const {
    return worldScreenMatrix_;
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
    auto noScaleViewMatrix = viewMatrix_;
    noScaleViewMatrix.setScale(1, 1);
    worldScreenMatrix_ = projectionMatrix_ * noScaleViewMatrix;
    auto e = event::Event{};
    e.type = event::EventType::ViewportChange;
    emit(e);
  }

  const auto& viewMatrix() {
    return viewMatrix_;
  }

  SkRect mapWorldToScreen(const SkRect& rect) {
    return viewProjectionMatrix_.mapRect(rect);
  }

  SkPoint mapScreenToWorld(float x, float y) {
    SkPoint point;
    SkMatrix inverse;
    if (worldScreenMatrix_.invert(&inverse)) {
      inverse.mapXY(x, y, &point);
    }
    return point;
  }

  float mapScreenToWorld(float length) {
    SkRect rect = SkRect::MakeWH(length, 0);
    SkMatrix inverse;
    if (worldScreenMatrix_.invert(&inverse)) {
      return inverse.mapRect(rect).width();
    }
    return inverse.getMaxScale() * length;
  }

  auto width() const { return width_; }
  auto height() const { return height_; }
  auto devicePixelRatio()  const { return devicePixelRatio_; }

private:
	SkMatrix viewMatrix_;
	SkMatrix projectionMatrix_;
  SkMatrix viewProjectionMatrix_;
  SkMatrix worldScreenMatrix_;
  uint32_t width_ = 800;
  uint32_t height_ = 600;
  float devicePixelRatio_ = 1;
};
}
