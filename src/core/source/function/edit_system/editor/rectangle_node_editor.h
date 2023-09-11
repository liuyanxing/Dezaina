#pragma once

#include "event_system/event_system.h"
#include "node_editor.h"
#include "rectangle.h"

class RectangleNodeEditor : public NodeEditor {
public:
  RectangleNodeEditor(Desaina* desaina): NodeEditor(desaina) {};

  void bindEvents() {}
  
};
