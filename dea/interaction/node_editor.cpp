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

  // const auto [width, height] = translateCtrl_.getSize();
  // int index = 0;
  // bool isDraggingBound = false;
  // // auto pointerRadius = config::pointerRadius;
  // auto pointerRadius = 6;

  // if (y < pointerRadius) {
  //   index = 0;
  // } else if (x > width - pointerRadius) {
  //   index = 1;
  // } else if (y > height - pointerRadius) {
  //   index = 2;
  // } else if (x < pointerRadius) {
  //   index = 3;
  // } else {
  //   isDraggingBound = true;
  // }

  // if (isDraggingBound) {
  //   editor_.translate(event.locallocalWorldDx, event.dy);
  //   return;
  // }

  // if (editNodes_.size() == 1) {
  //   const std::array<node::Vector, 4> directions = {{ { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } } };
  //   const std::array<node::Vector, 4> anchors = {{ { 0.5, 1 }, { 0, 0.5 }, { 0.5, 0 }, { 1, 0.5 } } };
  //   // auto [dx, dy] = node::Vector{event->deltaX, event->deltaY} * directions[index];
  //   // editor_.resize(dx, dy, anchors[index]);
  // } else {
  //   // todo 处理选中多个图层
  // }
}

void NodeEditor::buildEditor() {
    SolidPaint strokePaint;
    auto& [r, g, b, a] = config::color::Primary;
    strokePaint.setColor({r, g, b, a});

    translateCtrl_.setName("bt");
    translateCtrl_.setStrokePaints({strokePaint});
    translateCtrl_.setStrokeWeight(config::size::Min);
    translateCtrl_.addEventListener(EventType::MouseDrag, [this](Event& e) {
      auto& event = static_cast<MouseEvent&>(e);
      editor_.translate(event.localWorldDx, event.localWorldDy);
    });
    appendToContainer(&translateCtrl_);

    int nodeIndex = 0;

    SolidPaint fillPaint;
    fillPaint.setColor({1, 1, 1, 1});
    for (auto& ctrl : resizeNodeCtrls_) {
      ctrl.setName("bs" + std::to_string(nodeIndex));
      ctrl.setFillPaints({fillPaint});
      ctrl.setStrokePaints({strokePaint});
      ctrl.setStrokeWeight(config::size::Min);
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& e) {
        const std::array<node::Vector, 4> directions = {{ { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } } };
        auto& event = static_cast<MouseEvent&>(e);
        auto direction = directions[nodeIndex];
        auto d = direction * node::Vector{event.localWorldDx, event.localWorldDy}.cross(direction);
        editor_.resize(d.x, d.y, directions[nodeIndex]);
      });
      nodeIndex++;
      // appendToContainer(&ctrl);
    }
    
    for (int i = 0; i < resizeEdgeCtrls_.size(); i++) {
      auto& ctrl = resizeEdgeCtrls_[i];
      ctrl.setName("be" + std::to_string(i));
      ctrl.addEventListener(EventType::MouseDrag, [this, i](Event& e) {
        const std::array<node::Vector, 4> directions = {{ { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } } };
        auto& event = static_cast<MouseEvent&>(e);
        auto direction = directions[i];
        auto d = node::Vector{event.localWorldDx, event.localWorldDy} * direction;
        editor_.resize(d.x, d.y, directions[i]);
      });
      appendToContainer(&ctrl);
    }

    for (int i = 0; i < rotateCtrls_.size(); i++) {
      auto& ctrl = rotateCtrls_[i];
      ctrl.setName("br" + std::to_string(i));
      ctrl.setSize({config::size::Small, config::size::Small});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        // handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
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
  translateCtrl_.setSize({size.width, size.height});
  auto bound = Rect(0, 0, size.width, size.height); 

  // todo use constraint to layout
  layoutRectsToCornersOfRect(resizeNodeCtrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(rotateCtrls_, bound.makeOutset(6, 6));
  layoutResizeEdgeCtrls();
}

void NodeEditor::layoutResizeEdgeCtrls() {
  auto [width, height] = translateCtrl_.getSize();
  auto edgeWidth = width - config::size::Small;
  auto edgeHeight = height - config::size::Small;
  resizeEdgeCtrls_[0].setSize({edgeWidth, 1});
  resizeEdgeCtrls_[1].setSize({1, edgeHeight});
  resizeEdgeCtrls_[2].setSize({edgeWidth, 1});
  resizeEdgeCtrls_[3].setSize({1, edgeHeight});
  Matrix matrix;
  matrix.setTranslate(config::size::Small / 2, -0.5);
  resizeEdgeCtrls_[0].setTransform(matrix);
  matrix.setTranslate(width - 0.5, config::size::Small / 2);
  resizeEdgeCtrls_[1].setTransform(matrix);
  matrix.setTranslate(config::size::Small / 2, height - 0.5);
  resizeEdgeCtrls_[2].setTransform(matrix);
  matrix.setTranslate(-0.5, config::size::Small / 2);
  resizeEdgeCtrls_[3].setTransform(matrix);
}

}  // namespace dea::interaction
