#pragma once

#include <cmath>
#include <cstdint>
#include "event.h"
#include "node.h"
#include "node/node.h"
#include "node/utility.h"
#include <optional>

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

  void setProjectionMatrix(const node::Matrix& matrix) {
    projectionMatrix_ = matrix;
    updateVPMatrix();
  }

  void setViewMatrix(const node::Matrix& matrix) {
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

  auto mapWorldToScreen(const node::Size& size) {
    auto [width, height] = viewProjectionMatrix_.mapPoint({size.width, size.height});
    return node::Size{std::abs(width), std::abs(height)};
  }

  float mapWorldToScreen(float length) {
  }

  node::Vector mapScreenToWorld(float x, float y) {
    
  }

  float mapScreenToWorld(float length) {
    auto rect = node::Rect{};
    auto im = viewProjectionMatrix_.getInverse();
    return im.value().getScaleX() * length;
  }

  auto getScreenSize(node::NodeConstPtr node) {
    return mapWorldToScreen(node::getSize(node));
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
