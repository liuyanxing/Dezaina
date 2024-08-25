#include "interaction.h"
#include "node/src/node-base/type.generated.h"
#include "selection.h"
#include "rectangle_editor.h"
#include "spdlog/spdlog.h"

namespace dea::interaction {

using namespace event;
using namespace node;

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

  if (selection_.getSelection().size() > 1) {
    node_editor_ = std::make_unique<NodeEditor>();
  } else {
    auto* node = selection_.getSelection()[0];
    if (auto* rectangleNode = node::node_cast<node::RectangleNode*>(node); !node_editor_) {
      // node_editor_ = std::make_unique<RectangleEditor>(rectangleNode);
      node_editor_ = std::make_unique<NodeEditor>();
    }
  }

  if (node_editor_ == nullptr) {
    return;
  }
  node_editor_->update(selection_.getSelectionTransform(), selection_.getSelectionBound());
  auto* editorContainer = node_editor_->getContainer();
  if (!page_.findChild(editorContainer)) {
    appendToContainer(editorContainer);
  }
  // dump();
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

void Interaction::dump() {
  Iter iter(&page_);
  spdlog::info("dumping page");
  while (iter.isValid()) {
    auto* node = iter.get();
    auto* parent = iter.getParent();
    spdlog::info("node: {}, parent: {}", getNodeTypeString(node), getNodeTypeString(parent));
    ++iter;
  }
  spdlog::info("dump end");
}

}