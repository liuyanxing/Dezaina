#include "edit_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "editor/bound_editor.h"
#include "util/node_props.h"
#include "desaina.h"
#include <iostream>
#include "edit_system/editor/rectangle_node_editor.h"
#include "util/skia.h"

void EditSystem::bindEvents() {
  desaina_->selectSystem.addEventListener(EventType::kSelectionChange, [this](Event* event) {
    setEditorBySelection();
  });
  
  addEventListener(EventType::kAny, [this](Event* event) {
    if (editor_) {
      editor_->emit(event);
    }
  });
}

void EditSystem::setEditorBySelection() {
  auto selectedNodes = desaina_->document.getSelectedNodes();
  if (selectedNodes.size() == 0) {
    editor_ = nullptr;
    return;
  }
  
  if (selectedNodes.size() == 1) {
    auto node = selectedNodes[0];
    switch (node->get_type()) {
      case NodeType::ROUNDED_RECTANGLE:
      case NodeType::RECTANGLE: {
        editor_ = std::make_unique<RectangleNodeEditor>(desaina_);
        break;
      }
      default: {
        break;
      }
    }
  } else {
    editor_ = std::make_unique<NodeEditor>(desaina_);
  }
}

void EditSystem::afterTick() {
  if (editor_ != nullptr) {
    editor_->update();
  }
}
