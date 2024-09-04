#pragma once

#include "node_editor.h"

namespace dea::interaction {

class RectangleEditor : public NodeEditor {
 public:
  RectangleEditor(node::RectangleNode* node);

  void buildEditor();
  void update(const std::vector<node::Node*>& nodes) override;

private:
  std::array<Rectangle, 4> cornerSizeCtrls_;
  void handleDragResizeCornerCtrl(int index, const node::Vector& moveAxis, event::MouseEvent &event);
  node::RectangleNode* node_;
};

}
