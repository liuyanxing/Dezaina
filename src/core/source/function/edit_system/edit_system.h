#pragma once

#include "base_type.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "include/core/SkPoint.h"
#include "system/system.h"
#include <memory>
#include <vector>

class Desaina;

class EditSystem : public System {
 public:
  EditSystem(Desaina* desaina);
  ~EditSystem() = default;
 
  EditorView* getEditor() {
    return editorView_.get();
  }
  void setEditor(std::unique_ptr<EditorView>&& editor) {
    editorView_ = std::move(editor);
    auto event = Event::Builder(EventType::kEditorChagne).build();
    emit(event);
  }

  void selectCtrlNodeByPoint(const SkPoint& point);

  void afterTick() override;
  
 private:
  void bindEvents();
  void setEditorBySelection();
 
  Desaina* desaina_;
  std::unique_ptr<EditorView> editorView_;
};
