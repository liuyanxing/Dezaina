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
  BoundEditor(Frame& parent, document::Editor& editor) : editor_(editor) {
    node::Container::append(&container_, &parent);
    buildEditor();
  };

  Frame *getContainer() { return &container_; }
  void getNearestResizeCtrl(node::Vector worldPoint);
  void appendToContainer(node::Node *node) { node::Container::append(node, &container_); }
  void update();
  void invalidate() {
		if (auto* parent = container_.getParent()) {
			node::Container::remove(&container_, parent);
		}
  }

protected:
  Frame container_;
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
