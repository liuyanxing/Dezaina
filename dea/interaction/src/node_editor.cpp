#include "node_editor.h"
#include "config/size.h"
#include "document/src/document.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/rectangle.h"
#include <array>
#include "dezaina.h"
#include "utility.h"
#include "config/config.h"

namespace dea::interaction {

using namespace node;
using namespace event;

void NodeEditor::handleDragResizeCtrlNode(int index, event::MouseEvent& event) {
  // if (desaina_->document.getSelectedNodes().size() == 1) {
  //   const std::array<SkVector, 4> directions = {{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };
  //   const std::array<SkPoint, 4> anchors = {{ { 1, 1 }, { 0, 1 }, { 0, 0 }, { 1, 0 } } };
  //   auto [dx, dy] = SkVector{event->deltaX, event->deltaY} * directions[index];
  //   desaina_->getEditor()->resize(dx, dy, anchors[index]);
  // } else {
  //   // todo 处理选中多个图层
  // }

}

void NodeEditor::handleDragResizeCtrlEdge(event::MouseEvent& event) {
  // const auto& transform = bound_ctrl_.get_transform();
  // const auto [x, y] = base::mapPointToLocal({event->clientX, event->clientY}, util::toSkMatrix(transform));
  // const auto [width, height] = bound_ctrl_.get_size();
  // int index = 0;
  // auto pointerRadius = config::pointerRadius;
  // if (x > width - pointerRadius) {
  //   index = 1;
  // } else if (y > height - pointerRadius) {
  //   index = 2;
  // } else if (x < pointerRadius) {
  //   index = 3;
  // }

  // if (desaina_->document.getSelectedNodes().size() == 1) {
  // } else {
  //   // todo 处理选中多个图层
  // }
}

void NodeEditor::buildEditor() {
    SolidPaint strokePaint;
    auto& [r, g, b, a] = config::color::Primary;
    strokePaint.setColor({r, g, b, a});
    bound_ctrl_.setStrokePaints({strokePaint});
    bound_ctrl_.setStrokeWeight(config::size::Min);
    bound_ctrl_.addEventListener(EventType::MouseDrag, [this](Event& event) {
      handleDragResizeCtrlEdge(static_cast<MouseEvent&>(event));
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
        handleDragResizeCtrlNode(nodeIndex, static_cast<MouseEvent&>(event));        
      });
      nodeIndex++;
      appendToContainer(&ctrl);
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

void NodeEditor::update(const SkMatrix& transform, const SkSize& size) {
  container_.setTransform(utility::toMatrix(transform));
  container_.setSize({size.width(), size.height()});
  bound_ctrl_.setSize({size.width(), size.height()});
  SkRect bound = SkRect::MakeWH(size.width(), size.height()); 
  layoutRectsToCornersOfRect(nodeResizeCtrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(nodeRotateCtrls_, bound.makeOutset(6, 6));
}

}