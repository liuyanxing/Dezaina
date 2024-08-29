#include "interaction.h"
#include "dezaina.h"
#include "document/src/document.h"
#include "event/src/primitives.h"
#include "node/src/node-base/type.generated.h"
#include "selection.h"
#include "rectangle_editor.h"
#include "spdlog/spdlog.h"

namespace dea::interaction {

using namespace event;
using namespace node;
using namespace document;

Interaction::Interaction() {
  page_.setBackgroundColor({0, 0, 0, 0});
}

SkSize Interaction::GetItersectBound(node::Vector size) {
  return  Dezaina::instance().getViewport().mapWorldToScreen(SkSize{size.x, size.y});
}

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
    // node_editor_ = std::make_unique<NodeEditor>();
  } else {
    auto* node = selection_.getSelection()[0];
    if (auto* rectangleNode = node::node_cast<node::RectangleNode*>(node); !node_editor_) {
      // node_editor_ = std::make_unique<RectangleEditor>(rectangleNode);
      node_editor_ = std::make_unique<NodeEditor>(&selection_.getSelection());
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
  if (node_editor_ != nullptr) {
    node_editor_->onEvent(event);
  }
  selection_.onEvent(event);
  creation_.onEvent(event);

  InteractionListener::onEvent(event);
}

void Interaction::onBeforeRender(event::Event& event)  {
  updateSelection();
};

void Interaction::onAfterTick(Event& event) {
  static bool first = true;
  if (first) {
    first = false;
    Dezaina::instance().getDocument().addEventListener(EventType::PageChange, [this](Event& event) {
      selection_.setIter(Document::IterWithWorldMatrix{Dezaina::instance().getDocument().currentPage()});
    });
  }
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