#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "node/rectangle.h"
#include "node/frame.h"
#include <array>

namespace dea::interaction {

class Desaina;

class NodeEditor {
public:
  NodeEditor() {
    buildEditor();
  }
  virtual ~NodeEditor() = default;

  Frame* getContainer() { return &container_; }
  virtual void update(const std::vector<node::Node*>& nodes);
  void update(const SkMatrix& transform, const SkRect& bound);
  void appendChildToContainer(node::Node* node) { container_.appendChild(node); }

protected:
  Frame container_;
  Rectangle bound_ctrl_;
  std::array<Rectangle, 4> node_resize_ctrls_;
  std::array<Rectangle, 4> node_rotate_ctrls_;

  void buildEditor();
  SkRect caculateSelectionBound();
  void handleDragResizeCtrlNode(int index, event::MouseEvent &event);
  void handleDragRotateCtrlNode(int index, event::MouseEvent &event);
  void handleDragResizeCtrlEdge(event::MouseEvent &event);
};

}
