#pragma once

#include "editor.h"
#include "bound_editor.h"
#include "event_system/event_system.h"

class NodeEditor : public Editor {
public:
  NodeEditor(Desaina* document): Editor(document), boundEditor_(this) {};
  virtual ~NodeEditor() = default;
  
  virtual void update() {
    boundEditor_.update();
    Editor::update();
  };

  virtual void getPath(SkPath& fillPath, SkPath& strokePath) {
    boundEditor_.getPath(fillPath, strokePath);
  };
  
  void bindEvents();
  BoundEditor boundEditor_;
};
