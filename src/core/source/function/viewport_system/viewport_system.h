#pragma once

#include "event_system/event_emitter.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"

class Desaina;
class ViewPort: public EventEmitter {
public:
  ViewPort(Desaina* desaina);

  void tick() {};
  void bindEvents();
  const auto& getVPMatrix() {
    return view_projection_matrix_;
  }

  const auto& getProjectionMatrix() {
    return projection_matrix_;
  }

  const auto& getViewMatrix() {
    return view_matrix_;
  }

  SkRect mapWorldToScreen(const SkRect& rect) {
    return view_projection_matrix_.mapRect(rect);
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
    SkPoint point;
    SkMatrix inverse;
    if (world_screen_matrix_.invert(&inverse)) {
      inverse.mapXY(1, 0, &point);
    }
    return point.length() * length;
  }

private:
  Desaina *desaina_;
	SkMatrix view_matrix_;
	SkMatrix projection_matrix_;
  SkMatrix view_projection_matrix_;
  SkMatrix world_screen_matrix_;
  int width_ = 800;
  int height_ = 600;
  float devicePixelRatio_ = 1;
};
