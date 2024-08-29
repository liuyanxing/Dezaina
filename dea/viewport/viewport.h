#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include <cmath>
#include <cstdint>
#include "event.h"
#include "private/base/SkPoint_impl.h"

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
    auto noScaleViewMatrix = viewMatrix_;
    noScaleViewMatrix.setScale(1, 1);
    worldScreenMatrix_ = projectionMatrix_ * noScaleViewMatrix;
    auto e = event::Event{};
    e.type = event::EventType::ViewportChange;
    emit(e);
  }

  const auto getHudProjectionViewMatrix() {
    SkMatrix hubMatrix = viewProjectionMatrix_;
    hubMatrix.postScale(1 / viewMatrix_.getScaleX(), 1 / viewMatrix_.getScaleY());
    return hubMatrix;
  }

  SkRect mapWorldToScreen(const SkRect& rect) {
    return viewProjectionMatrix_.mapRect(rect);
  }

  SkPoint mapWorldToScreen(const SkPoint& point) {
    return viewProjectionMatrix_.mapPoint(point);
  }

  SkSize mapWorldToScreen(const SkSize& size) {
    SkRect rect = mapWorldToScreen(SkRect::MakeWH(size.width(), size.height()));
    return {rect.width(), rect.height()};
  }

  float mapWorldToScreen(float length) {
    SkRect rect = SkRect::MakeWH(length, 0);
    SkRect mapped = viewProjectionMatrix_.mapRect(rect);
    return mapped.width();
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
    if (viewProjectionMatrix_.invert(&inverse)) {
      return std::copysign(inverse.mapRect(rect).width(), length);
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
