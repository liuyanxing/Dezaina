#pragma once

#include "edit_system/editor/editor.h"
#include "event_system/event_system.h"
#include "node_editor.h"
#include "rectangle.h"

class RectangleNodeEditor : public NodeEditor {
public:
  RectangleNodeEditor(Desaina* desaina): NodeEditor(desaina, EditorType::kRectangel) {};

  void bindEvents() {}
  
};
