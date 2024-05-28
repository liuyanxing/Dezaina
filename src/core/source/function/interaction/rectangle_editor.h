#pragma once

#include "include/private/base/SkPoint_impl.h"
#include "node_editor.h"

class RectangleEditor : public NodeEditor {
 public:
  RectangleEditor(Desaina* desaina) : NodeEditor(desaina) {}

  void buildEditor();
  void update(const vector<Node*>& nodes) override;

private:
  std::array<Rectangle, 4> corner_size_ctrls_;

  void handleDragResizeCornerCtrl(int index, const SkVector& moveAxis, MouseEvent *event);
};