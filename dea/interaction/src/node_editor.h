#pragma once

#include "event_system/event_system.h"
#include "event_system/mouse_event.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "node/rectangle.h"
#include "node/frame.h"
#include <array>

class Desaina;

class NodeEditor {
public:
  NodeEditor(Desaina* desaina) : desaina_(desaina) {
    buildEditor();
  }
  virtual ~NodeEditor() = default;

  Frame* getContainer() { return &container_; }
  virtual void update(const vector<Node*>& nodes);
  void update(const SkMatrix& transform, const SkRect& bound);
  void appendChildToContainer(Node* node) { container_.appendChild(node); }

protected:
  Desaina* desaina_;
  Frame container_;
  Rectangle bound_ctrl_;
  std::array<Rectangle, 4> node_resize_ctrls_;
  std::array<Rectangle, 4> node_rotate_ctrls_;

  void buildEditor();
  SkRect caculateSelectionBound();
  void handleDragResizeCtrlNode(int index, MouseEvent *event);
  void handleDragRotateCtrlNode(int index, MouseEvent *event);
  void handleDragResizeCtrlEdge(MouseEvent *event);
};
