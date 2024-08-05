#include "node_editor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/rectangle.h"
#include <array>
#include "dezaina.h"
#include "utility.h"
// #include "config/interaction.h"

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
    strokePaint.setColor({0, 0, 0, 255});
    bound_ctrl_.setStrokePaints({strokePaint});
    bound_ctrl_.setStrokeWeight(1.0);
    bound_ctrl_.addEventListener(EventType::MouseDrag, [this](Event& event) {
      handleDragResizeCtrlEdge(static_cast<MouseEvent&>(event));
    });
    appendChildToContainer(&bound_ctrl_);

    int nodeIndex = 0;
    for (auto& ctrl : node_resize_ctrls_) {
      SolidPaint fillPaint;
      fillPaint.setColor({255, 255, 255, 255});
      ctrl.setFillPaints({fillPaint});
      fillPaint.setColor({0, 0, 0, 255});
      ctrl.setStrokePaints({strokePaint});
      ctrl.setStrokeWeight(1.0);
      ctrl.setSize({20, 20});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        handleDragResizeCtrlNode(nodeIndex, static_cast<MouseEvent&>(event));        
      });
      nodeIndex++;
      appendChildToContainer(&ctrl);
    }

    nodeIndex = 0;
    for (auto& ctrl : node_rotate_ctrls_) {
      ctrl.setSize({20, 20});
      ctrl.addEventListener(EventType::MouseDrag, [this, nodeIndex](Event& event) {
        // handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
      nodeIndex++;
    }
}

void NodeEditor::update(const SkMatrix& transform, const SkSize& size) {
  container_.setTransform(utility::toMatrix(transform));
  container_.setSize({size.width(), size.height()});
  bound_ctrl_.setSize({size.width(),size.height()});
  SkBound bound = SkBound::MakeXYWH(0, 0, bound.width(), bound.height());
  layoutRectsToCornersOfRect(node_resize_ctrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(node_rotate_ctrls_, bound.makeOutset(6, 6));
}

}