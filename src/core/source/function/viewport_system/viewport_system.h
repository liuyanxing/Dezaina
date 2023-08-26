#pragma once

#include "event_system/event_emitter.h"
#include "include/core/SkMatrix.h"
#include "system/system.h"

class Desaina;
class ViewPortSystem: public System {
public:
  ViewPortSystem(Desaina* desaina);

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

private:
  Desaina *desaina_;
	SkMatrix view_matrix_;
	SkMatrix projection_matrix_;
  SkMatrix view_projection_matrix_;
  int width_ = 800;
  int height_ = 600;
  float devicePixelRatio_ = 1;
};