#pragma once

#include <cmath>
#include <cstdint>
#include "event.h"
#include "node.h"
#include "node/node.h"
#include "node/node_base.generated.h"
#include "node/utility.h"
#include <optional>

namespace dea {
class Viewport : public event::EventEmitter {
public:
  void update(uint32_t width, uint32_t height, float devicePixelRatio);

  void translate(float dx, float dy);
  void scale(float sx, float sy, float px = 0, float py = 0);
  void reset();

  const auto& getVPMatrix() const {
    return viewProjectionMatrix_;
  }

  const auto& getViewMatrix() {
    return viewMatrix_;
  }

  const auto getViewScale()  const {
    return viewMatrix_.getScaleX();
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

  auto mapWorldToScreen(const node::Vector& point) {
    return viewProjectionMatrix_ * point;
  }

  auto mapWorldToScreen(float x) {
    return getWorldToScreenScale() * x;
  }

  auto mapWorldToScreen(const node::Size& size) {
    return node::Size{ mapWorldToScreen(size.width), mapWorldToScreen(size.height) };
  }

  auto mapScreenToWorld(float x, float y) {
    auto inv = viewProjectionMatrix_.getInverse().value_or(node::Matrix{});
    return inv.mapVector(node::Vector{x, y});
  }

  auto getWorldSize(float length) {
    return mapScreenToWorld(length, 0).x;
  }

  // get the size of a world unit in screen space
  auto getScreenSize(float length) {
    return mapWorldToScreen(node::Vector{1, 0}).length() * length;
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

  float getWorldToScreenScale() const {
    return viewMatrix_.getScaleX() / devicePixelRatio_;
  }
};

} // namespace dea
