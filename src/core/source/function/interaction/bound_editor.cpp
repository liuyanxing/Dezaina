#include "bound_editor.h"
#include "include/private/base/SkPoint_impl.h"
#include <array>

void BoundEditor::handleDragResizeCtrlNode(int index, MouseEvent *event) {
  if (desaina_->document.getSelectedNodes().size() == 1) {
    const std::array<SkVector, 4> directions = {{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } } };
    const std::array<SkPoint, 4> anchors = {{ { 1, 1 }, { 0, 1 }, { 0, 0 }, { 1, 0 } } };
    const auto& direction = directions[index];
    const auto& anchor = anchors[index];
    auto [dx, dy] = SkVector{event->deltaX, event->deltaY} * direction;
    desaina_->getEditor()->resize(dx, dy, anchor);
  } else {
    // todo 处理选中多个图层
  }

}