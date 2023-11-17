#pragma once

#include "base_type.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "system/system.h"
#include <memory>
#include <vector>

class Desaina;

class EditSystem : public System {
 public:
  EditSystem(Desaina* desaina) : desaina_(desaina) {
    bindEvents();
  };
  ~EditSystem() = default;
 
  EditorView* getEditor() {
    return editor_.get();
  }
  void setEditor(std::unique_ptr<EditorView>&& editor) {
    editor_ = std::move(editor);
    auto event = Event::Builder(EventType::kEditorChagne).build();
    emit(event);
  }

  void afterTick() override;
  
 private:
  void bindEvents();
  void setEditorBySelection();
 
  Desaina* desaina_;
  std::unique_ptr<EditorView> editor_;
};
