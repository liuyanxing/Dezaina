#pragma once

#include "node.h"
#include "node/container.h"
#include "node/frame.h"
#include "node/rectangle.h"
#include <array>
#include "document.h"

namespace dea::interaction {

class Desaina;

class BoundEditor {
public:
  BoundEditor(Frame& container, document::Editor& editor)
      : container_(container), editor_(editor) {
    buildEditor();
  };

  Frame *getContainer() { return &container_; }
  void getNearestResizeCtrl(node::Vector worldPoint);
  void appendToContainer(node::Node *node) { node::Container::append(&container_, node); }
  void update(const node::Matrix& transform, const node::Vector& size);

protected:
  Frame& container_;
  Rectangle translateCtrl_;
  std::array<Rectangle, 4> resizeNodeCtrls_;
  std::array<Rectangle, 4> resizeEdgeCtrls_;
  std::array<Rectangle, 4> rotateCtrls_;
  document::Editor &editor_;

  void initCtrls();
  void bindEvents();
  void buildEditor();
};

} // namespace dea::interaction
