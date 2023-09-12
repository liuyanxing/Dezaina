#include "node_editor.h"
#include "edit_system/editor/vector_node_editor.h"
#include "event_system/event.h"
#include "desaina.h"

void NodeEditor::bindEvents() {
  addEventListener(EventType::kMouseDoubleClick, [this](Event* event) {
    auto mouseEvent = static_cast<MouseEvent*>(event);
    desaina->editSystem.setEditor(std::make_unique<VectorNodeEditor>(desaina));
  });
}

