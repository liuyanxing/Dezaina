#include "desaina.h"
#include "viewport_system.h"
#include "event_system/event.h"
#include <iostream>

ViewPort::ViewPort(Desaina* desaina) {
  desaina_ = desaina;
}

void ViewPort::update() {
  const auto& [width, height, devicePixelRatio] = desaina_->getWindowInfo();
  width_ = width;
  height_ = height;
  devicePixelRatio_ = devicePixelRatio;
  float center_x = width_ * devicePixelRatio_ / 2.;
  float center_y = height_ * devicePixelRatio_ / 2.;
  projection_matrix_.setScale(devicePixelRatio_, devicePixelRatio_, -center_x, -center_y);
  updateVPMatrix();

  auto e = Event::Builder(EventType::kViewPortChange).build();
  emit(e);
}

void ViewPort::translate(float dx, float dy) {
  view_matrix_.preTranslate(-dx, dy);
  updateVPMatrix();
  Event::Builder builder(EventType::kViewPortChange);
  auto e = builder.build();
  emit(e);
}
