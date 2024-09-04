#include "node_editor.h"
#include "config/size.h"
#include "dezaina.h"
#include "document.h"
#include "node/rectangle.h"
#include "node/type.h"
#include "spdlog/spdlog.h"
#include "utility.h"
#include "config/config.h"
#include "utility/coords.h"
#include "viewport/viewport.h"

namespace dea::interaction {

using namespace node;
using namespace event;

// void NodeEditor::handleDragResizeCtrlNode(int index, event::MouseEvent& event) {
//   if (editedNodes_.size() == 1) {
//     const std::array<node::Vector, 4> directions = {{ { -1, -1 }, { 1, -1 }, { 1, 1 }, { -1, 1 } } };
//     const std::array<SkPoint, 4> anchors = {{ { 1, 1 }, { 0, 1 }, { 0, 0 }, { 1, 0 } } };
//     auto [dx, dy] = node::Vector{event->deltaX, event->deltaY} * directions[index];
//     editor_.resize(dx, dy, anchors[index]);
//   } else {
//     // todo 处理选中多个图层
//   }

// }

void NodeEditor::handleDragBoundCtrlNode(event::MouseEvent& event) {
  auto x = event.localX;
  auto y = event.localY;
  auto& viewport = Dezaina::instance().getViewport();
  auto size = bound_ctrl_.getSize();
  const auto [width, height] = viewport.mapWorldToScreen(node::Size{size.x, size.y});
  int index = 0;
  bool isDraggingBound = false;
  // auto pointerRadius = config::pointerRadius;
  auto pointerRadius = 6;

  if (y < pointerRadius) {
    index = 0;
  } else if (x > width - pointerRadius) {
    index = 1;
  } else if (y > height - pointerRadius) {
    index = 2;
  } else if (x < pointerRadius) {
    index = 3;
  } else {
    isDraggingBound = true;
  }

  if (isDraggingBound) {
    editor_.translate(event.worldDx, event.dy);
    return;
  }

  if (editNodes_.size() == 1) {
    const std::array<node::Vector, 4> directions = {{ { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } } };
    const std::array<node::Vector, 4> anchors = {{ { 0.5, 1 }, { 0, 0.5 }, { 0.5, 0 }, { 1, 0.5 } } };
    // auto [dx, dy] = node::Vector{event->deltaX, event->deltaY} * directions[index];
    // editor_.resize(dx, dy, anchors[index]);
  } else {
    // todo 处理选中多个图层
  }
}

void NodeEditor::buildEditor() {
    SolidPaint strokePaint;
    auto& [r, g, b, a] = config::color::Primary;
    strokePaint.setColor({r, g, b, a});

    bound_ctrl_.setStrokePaints({strokePaint});
    bound_ctrl_.setStrokeWeight(config::size::Min);
    bound_ctrl_.addEventListener(EventType::MouseDrag, [this](Event& event) {
      handleDragBoundCtrlNode(static_cast<MouseEvent&>(event));
    });
    appendToContainer(&bound_ctrl_);

    int nodeIndex = 0;

    SolidPaint fillPaint;
    fillPaint.setColor({1, 1, 1, 1});
    for (auto& ctrl : nodeResizeCtrls_) {
      ctrl.setFillPaints({fillPaint});
      ctrl.setStrokePaints({strokePaint});
      ctrl.setStrokeWeight(config::size::Min);
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        // handleDragResizeCtrlNode(nodeIndex, static_cast<MouseEvent&>(event));        
      });
      nodeIndex++;
      // appendToContainer(&ctrl);
    }

    nodeIndex = 0;
    for (auto& ctrl : nodeRotateCtrls_) {
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        // handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
      nodeIndex++;
    }
}

void NodeEditor::update() {
  node::Matrix transform;
  node::Size size;
  if (editNodes_.empty()) {
    return;
  } else if (editNodes_.size() == 1) {
    auto& viewport = Dezaina::viewport();
    auto* node = editNodes_[0];
    transform = document::getWorldMatrix(node);
    size = viewport.getScreenSize(node);
  } else {
    assert(false);
  }

  container_.setTransform(transform);
  container_.setSize({size.width, size.height});
  bound_ctrl_.setSize({size.width, size.height});
  auto bound = Rect(0, 0, size.width, size.height); 
  layoutRectsToCornersOfRect(nodeResizeCtrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(nodeRotateCtrls_, bound.makeOutset(6, 6));
}

}