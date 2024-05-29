#include "interaction.h"
#include "event_system/mouse_event.h"
#include "include/core/SkPath.h"
#include "interaction/selection.h"

void Interaction::bindEvents() {
}

void Interaction::tick() {
  handleSelection();
  handleHover();
}

void Interaction::handleSelection() {
  if (selection_.empty()) {
    if (node_editor_ != nullptr) {
      auto* editorContainer = node_editor_->getContainer();
      page_.removeChild(editorContainer); 
      node_editor_ = nullptr;
      return;
    }
    return;
  }

  if (node_editor_ == nullptr) {
    node_editor_ = std::make_unique<NodeEditor>(desaina_);
  }

  auto* editorContainer = node_editor_->getContainer();
  if (!page_.findChild(editorContainer)) {
    page_.appendChild(editorContainer);
  }
  node_editor_->update(selection_.getSelection());
}

void Interaction::handleHover() {
  auto* hoverNode = selection_.getHoverNode();
  if (hoverNode == nullptr) {
    // hover_.clearPath();
    return;
  }
  // hover_.setPath(SkPath());
}

void Interaction::handleMouseEvent(MouseEvent* event) {
  selection_.emit(*event);
}

