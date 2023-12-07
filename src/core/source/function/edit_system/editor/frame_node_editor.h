#pragma once

#include "edit_system/editor/editor.h"
#include "event_system/event_system.h"
#include "node_editor.h"

class FrameNodeEditor : public NodeEditor {
public:
  FrameNodeEditor(Desaina* desaina): NodeEditor(desaina, EditorType::kFrame) {};

  void bindEvents() {}
  
};