#pragma once

#include "document/editor.h"
#include "node/container.h"
#include "node/rectangle.h"
#include "document.h"

namespace dea::interaction {

class RadiusEditor {
 public:
  RadiusEditor(node::FrameNode& parent, document::Editor& editor) : editor_(editor) {
    node::Container::append(&container_, &parent);
    buildEditor();
  };

  void buildEditor();
  void update(base::v4<float> cornerSizes);

private:
  Frame container_;
  base::v4<Rectangle> cornerSizeCtrls_;
  document::Editor& editor_;
};

}
