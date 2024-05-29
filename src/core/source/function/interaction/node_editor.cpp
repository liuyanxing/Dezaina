#include "node_editor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "interaction/node/rectangle.h"
#include "util/skia.h"
#include "util.h"
#include <array>
#include <vector>
#include "desaina.h"

void NodeEditor::handleDragResizeCtrlNode(int index, MouseEvent *event) {
  if (desaina_->document.getSelectedNodes().size() == 1) {
    const std::array<SkVector, 4> directions = {{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };
    const std::array<SkPoint, 4> anchors = {{ { 1, 1 }, { 0, 1 }, { 0, 0 }, { 1, 0 } } };
    auto [dx, dy] = SkVector{event->deltaX, event->deltaY} * directions[index];
    desaina_->getEditor()->resize(dx, dy, anchors[index]);
  } else {
    // todo 处理选中多个图层
  }

}

void NodeEditor::buildEditor() {
    SolidPaint strokePaint;
    strokePaint.set_color({0, 0, 0, 255});
    bound_ctrl_.set_strokePaints({strokePaint});
    bound_ctrl_.set_strokeWeight(1.0);
    bound_ctrl_.addEventListener(EventType::kMouseDrag, [this](Event* event) {
      // handleDragResizeCtrlEdge(static_cast<MouseEvent*>(event));
    });
    container_.appendChild(&bound_ctrl_);

    int nodeIndex = 0;
    for (auto& ctrl : node_resize_ctrls_) {
      SolidPaint fillPaint;
      fillPaint.set_color({255, 255, 255, 255});
      ctrl.set_fillPaints({fillPaint});
      fillPaint.set_color({0, 0, 0, 255});
      ctrl.set_strokePaints({strokePaint});
      ctrl.set_strokeWeight(1.0);
      ctrl.set_size({20, 20});
      ctrl.addEventListener(EventType::kMouseDrag, [this, nodeIndex](Event* event) {
        handleDragResizeCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));        
      });
      nodeIndex++;
      container_.appendChild(&ctrl);
    }

    nodeIndex = 0;
    for (auto& ctrl : node_rotate_ctrls_) {
      ctrl.set_size({20, 20});
      ctrl.addEventListener(EventType::kMouseDrag, [this, nodeIndex](Event* event) {
        // handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
      nodeIndex++;
    }
}

void NodeEditor::update(const vector<Node*>& nodes) {
  SkRect bound = SkRect::MakeEmpty();
  if (nodes.size() == 1) {
    auto* node = nodes[0];
    // update(desaina_->nodeUtil.getScreenTransformMatrix(node), desaina_->nodeUtil.getScreenBound(node));
  } else {
    // todo 处理选中多个图层
  }
}

void NodeEditor::update(const SkMatrix& transform, const SkRect& bound) {
  container_.set_transform(util::toMatrix(transform));
  container_.set_size({bound.width(), bound.height()});
  bound_ctrl_.set_size({bound.width(), bound.height()});
  interaction_util::layoutRectsToCornersOfRect(node_resize_ctrls_, bound.makeOutset(2, 2));
  interaction_util::layoutRectsToCornersOfRect(node_rotate_ctrls_, bound.makeOutset(6, 6));
}

