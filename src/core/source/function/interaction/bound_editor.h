#pragma once

#include "change/change_type.h"
#include "desaina.h"
#include "desaina_node.h"
#include "event_system/mouse_event.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/rectangle.h"
#include "node/frame.h"
#include <array>

class BoundEditor {
public:
  BoundEditor(Desaina* desaina) : desaina_(desaina) {
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
private:
  Desaina* desaina_;
  Frame container_;
  Rectangle bound_ctrl_;
  std::array<Rectangle, 4> node_resize_ctrls_;
  std::array<Rectangle, 4> node_rotate_ctrls_;

  void handleSelectionChange();
  SkRect caculateSelectionBound();
  void handleDragResizeCtrlNode(int index, MouseEvent *event);
  void handleDragRotateCtrlNode(int index, MouseEvent *event);
  void handleDragResizeCtrlEdge(MouseEvent *event);
};
