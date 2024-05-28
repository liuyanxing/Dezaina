#include "node_editor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "interaction/node/rectangle.h"
#include "util/skia.h"
#include <array>
#include <vector>

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
      handleDragResizeCtrlEdge(static_cast<MouseEvent*>(event));
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
        handleDragRotateCtrlNode(nodeIndex, static_cast<MouseEvent*>(event));
      });
      nodeIndex++;
    }
}

void NodeEditor::update(const vector<Node*>& nodes) {
  SkRect bound = SkRect::MakeEmpty();
  if (nodes.size() == 1) {
    update(desaina_->nodeUtil.getLocalBound(nodes[0]));
  } else {
    // todo 处理选中多个图层
  }
}

static void layoutRectsToCornersOfRect(std::array<Rectangle, 4>& rects, const SkRect& frame) {
  SkMatrix matrix;
  matrix.setTranslate(frame.left(), frame.top());
  auto const frameWidth = frame.width();
  auto const frameHeight = frame.height();
  const SkVector offsets[4] = {
    { 0, 0 },
    { frameWidth - rects[1].get_size().x, 0 },
    { frameWidth - rects[2].get_size().x, frameHeight - rects[2].get_size().y },
    { 0, frameHeight - rects[3].get_size().y }
  };

  for (int i = 0; i < 4; i++) {
    auto& offset = offsets[i];
    auto& rect = rects[i];
    matrix.setTranslate(offset.x(), offset.y());
    rect.set_transform(util::toMatrix(matrix));
  }
}

void NodeEditor::update(const SkRect& bound) {
  bound_ctrl_.set_size({bound.width(), bound.height()});
  layoutRectsToCornersOfRect(node_resize_ctrls_, bound.makeOutset(2, 2));
  layoutRectsToCornersOfRect(node_rotate_ctrls_, bound.makeOutset(6, 6));
}
