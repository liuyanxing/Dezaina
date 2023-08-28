#include "desaina.h"
#include "viewport_system.h"
#include "event_system/event.h"
#include <iostream>

ViewPortSystem::ViewPortSystem(Desaina* desaina) {
  desaina_ = desaina;
  bindEvents();
}

void ViewPortSystem::bindEvents() {
  addEventListener(EventType::kWindowResize, [this](Event* event) {
    const auto& [width, height, devicePixelRatio] = desaina_->getWindowInfo();
    width_ = width;
    height_ = height;
    devicePixelRatio_ = devicePixelRatio;
    float center_x = width_ * devicePixelRatio_ / 2.;
    float center_y = height_ * devicePixelRatio_ / 2.;
    projection_matrix_.setScale(devicePixelRatio_, devicePixelRatio_, -center_x, -center_y);
    view_projection_matrix_ = projection_matrix_ * view_matrix_ ;
    auto e = Event::Builder(EventType::kViewPortChange).build();
    emit(e);
  });

  addEventListener(EventType::kMouseWheel, [this](Event* event) {
		auto mouseEvent = static_cast<MouseEvent*>(event);
		auto x = mouseEvent->x;
		auto y = mouseEvent->y;
    std::cout << "mouse wheel: " << x << " " << y << std::endl;
    view_matrix_.preTranslate(-x * 5, y * 5);
    view_projection_matrix_ = projection_matrix_ * view_matrix_ ;
    Event::Builder builder(EventType::kViewPortChange);
    auto e = builder.build();
    emit(e);
  });
}