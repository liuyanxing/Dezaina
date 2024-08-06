#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "node/rectangle.h"
#include "node/frame.h"
#include "node/container.h"
#include <array>

namespace dea::interaction {

class Desaina;

class NodeEditor {
public:
  NodeEditor(const SkMatrix& transform, const SkSize& size) {
    buildEditor();
    update(transform, size);
  }
  NodeEditor() {
    buildEditor();
  };
  virtual ~NodeEditor() = default;

  Frame* getContainer() { return &container_; }
  virtual void update(const std::vector<node::Node*>& nodes) {};
  void update(const SkMatrix& transform, const SkRect& bound);
  void appendToContainer(node::Node* node) {
    appendChild(&container_, node);
  }

protected:
  Frame container_;
  Rectangle bound_ctrl_;
  std::array<Rectangle, 4> nodeResizeCtrls_;
  std::array<Rectangle, 4> nodeRotateCtrls_;

  void buildEditor();
  SkRect caculateSelectionBound();
  void handleDragResizeCtrlNode(int index, event::MouseEvent &event);
  void handleDragRotateCtrlNode(int index, event::MouseEvent &event);
  void handleDragResizeCtrlEdge(event::MouseEvent &event);
};

}
