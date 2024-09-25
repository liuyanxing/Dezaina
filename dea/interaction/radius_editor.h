#pragma once

#include "document/editor.h"
#include "node/container.h"
#include "node/rectangle.h"
#include "document.h"

namespace dea::interaction {

class RadiusEditor {
 public:
  RadiusEditor(node::FrameNode& container, document::Editor& editor) : editor_(editor) {
    buildEditor(container);
  };

  void buildEditor(node::FrameNode& container);
  void update(node::Vector size, std::array<float, 4> cornerSizes);

private:
  std::array<Rectangle, 4> cornerSizeCtrls_;
  document::Editor& editor_;
};

}
