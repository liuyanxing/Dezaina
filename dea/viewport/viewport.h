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
    return view_projection_matrix_;
  }

  const auto& projectionMatrix() const {
    return projection_matrix_;
  }

  void setProjectionMatrix(const SkMatrix& matrix) {
    projection_matrix_ = matrix;
    updateVPMatrix();
  }

  void setViewMatrix(const SkMatrix& matrix) {
    view_matrix_ = matrix;
    updateVPMatrix();
  }

  void updateVPMatrix() {
    view_projection_matrix_ = projection_matrix_ * view_matrix_ ;
    world_screen_matrix_ = view_projection_matrix_;
    world_screen_matrix_.postScale(1 / devicePixelRatio_, 1 / devicePixelRatio_);
    auto e = event::Event{};
    e.type = event::EventType::ViewportChange;
    emit(e);
  }

  const auto& viewMatrix() {
    return view_matrix_;
  }

  SkRect mapWorldToScreen(const SkRect& rect) {
    return view_projection_matrix_.mapRect(rect);
  }

  SkSize mapWorldToScreen(const SkSize& size) {
    SkRect rect = mapWorldToScreen(SkRect::MakeWH(size.width(), size.height()));
    return {rect.width(), rect.height()};
  }

  float mapWorldToScreen(float length) {
    SkRect rect = SkRect::MakeWH(length, 0);
    SkRect mapped = view_projection_matrix_.mapRect(rect);
    return mapped.width();
  }

  SkPoint mapScreenToWorld(float x, float y) {
    SkPoint point;
    SkMatrix inverse;
    if (world_screen_matrix_.invert(&inverse)) {
      inverse.mapXY(x, y, &point);
    }
    return point;
  }

  float mapScreenToWorld(float length) {
    SkRect rect = SkRect::MakeWH(length, 0);
    SkMatrix inverse;
    if (world_screen_matrix_.invert(&inverse)) {
      return inverse.mapRect(rect).width();
    }
    return inverse.getMaxScale() * length;
  }

  auto width() const { return width_; }
  auto height() const { return height_; }
  auto devicePixelRatio()  const { return devicePixelRatio_; }

private:
	SkMatrix view_matrix_;
	SkMatrix projection_matrix_;
  SkMatrix view_projection_matrix_;
  SkMatrix world_screen_matrix_;
  uint32_t width_ = 800;
  uint32_t height_ = 600;
  float devicePixelRatio_ = 1;
};
}
