#pragma once

#include "base_type.h"
#include "edit_system/editor/editor.h"
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
 
 Editor* getEditor() {
   return editor_.get();
 }

  void tick() override;
  
 private:
  void bindEvents();
  void setEditorBySelection();
 
  Desaina* desaina_;
  std::unique_ptr<Editor> editor_;
};
