#include "interaction.h"
#include "dezaina.h"
#include "document.h"
#include "node.h"
#include "node/node.h"
#include "selection.h"
#include "spdlog/spdlog.h"

namespace dea::interaction {

using namespace event;
using namespace node;
using namespace document;

Interaction::Interaction(Document& doc) : doc_(doc) {
  page_.setBackgroundColor({0, 0, 0, 0});
  doc_.addEventListener(EventType::PageChange, [this](Event& event) {
    selection_.setIter(Document::IterWithWorldMatrix{doc_.currentPage()});
  });

  selection_.onSelectionChange([this](const NodeArary& nodes) {
    handleSelectionChange(nodes);
  });
}


void Interaction::handleSelectionChange(const node::NodeArary& selection) {
  if (selection.empty()) {
    return;
  }

  node::NodeIdArray ids;
  for (auto* node : selection) {
    ids.push_back(node->getGuid());
  }
  doc_.editor().select(ids);
}

node::Size Interaction::GetItersectBound(node::Vector size) {
  return  Dezaina::instance().getViewport().mapWorldToScreen(node::Size{size.x, size.y});
}

void Interaction::updateNodeEditor() {
  auto& selection = doc_.getSelection();
  if (selection.empty()) {
    if (node_editor_ != nullptr) {
      auto* editorContainer = node_editor_->getContainer();
      page_.removeChild(editorContainer); 
      node_editor_ = nullptr;
      return;
    }
    return;
  }

  if (selection.size() > 1) {
  } else {
    auto* node = doc_.getNodeById(selection[0]);
    if (auto* rectangleNode = node::node_cast<node::RectangleNode*>(node); !node_editor_) {
      node_editor_ = std::make_unique<NodeEditor>(node::NodeArary{node});
    }
  }

  if (node_editor_ == nullptr) {
    return;
  }
  node_editor_->update();
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
  if (!doc_.loaded()) {
    return;
  }

  if (node_editor_ != nullptr) {
    node_editor_->onEvent(event);
  }

  selection_.onEvent(event);
  creation_.onEvent(event);

  InteractionListener::onEvent(event);
}

void Interaction::onBeforeRender(event::Event& event)  {
  updateNodeEditor();
};

void Interaction::onAfterTick(Event& event) {
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