#include "rectangle_editor.h"
#include "include/private/base/SkPoint_impl.h"
#include "viewport_system/viewport_system.h"

void RectangleEditor::buildEditor() {
  SkVector moveAxises[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  for (int i = 0; i < 4; i++) {
    SkVector::Normalize(&moveAxises[i]);
    auto& ctrl = corner_size_ctrls_[i];
    ctrl.set_size({20, 20});
    ctrl.addEventListener(EventType::kMouseDrag, [this, i, moveAxises](Event* event) {
      handleDragResizeCornerCtrl(i, moveAxises[i], static_cast<MouseEvent*>(event));
    });
    appendChildToContainer(&ctrl);
  }
}

void RectangleEditor::handleDragResizeCornerCtrl(int index, const SkVector& moveAxis, MouseEvent *event) {
  auto moveDistance = moveAxis.cross({event->deltaX, event->deltaY});
  auto delta = desaina_->viewPort.mapScreenToWorld(moveDistance);
}