#pragma once

#include "editor.h"
#include "bound_editor.h"
#include "event_system/event_system.h"

class NodeEditor : public Editor {
public:
  NodeEditor(Desaina* desaina, EditorType type = EditorType::kNode): Editor(type, desaina), boundEditor_(this) {
    bindEvents();
  };
  virtual ~NodeEditor() = default;
  
  virtual void update() {
    Editor::update();
    boundEditor_.update();
  };

  virtual void getPath(SkPath& fillPath, SkPath& strokePath) {
    boundEditor_.getPath(fillPath, strokePath);
  };
  
  void bindEvents();
  BoundEditor boundEditor_;
};
