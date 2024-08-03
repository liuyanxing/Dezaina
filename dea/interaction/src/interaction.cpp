#include "interaction.h"
#include "selection.h"

namespace dea::interaction {

using namespace event;

void Interaction::updateSelection() {
  if (selection_.empty()) {
    if (node_editor_ != nullptr) {
      auto* editorContainer = node_editor_->getContainer();
      page_.removeChild(editorContainer); 
      node_editor_ = nullptr;
      return;
    }
    return;
  }

  if (node_editor_) {
    return;
  }

  if (node_editor_ == nullptr) {
    node_editor_ = std::make_unique<NodeEditor>();
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

void Interaction::onEvent(event::Event& event) {
  selection_.onEvent(event);
  creation_.onEvent(event);
  InteractionListener::onEvent(event);
}

void Interaction::onAfterTick(Event& event) {
  updateSelection();
  handleHover();
}

}