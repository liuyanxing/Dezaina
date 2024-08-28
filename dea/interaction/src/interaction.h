#pragma once

#include <memory>
#include "creation.h"
#include "event.h"
#include "event/src/listener.h"
#include "interaction/src/listener.h"
#include "node_editor.h"
#include "selection.h"
#include "node/path.h"
#include "node/page.h"

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  Interaction() {
    page_.setBackgroundColor({0, 0, 0, 0});
  }

  auto* root() { return &page_; }

  void dump();

  class Iter : public utility::NodeIter {
  public:
    Iter(node::Node* node) :
    NodeIter(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent();}) {}
  };

  class IterWithWorldMatrix : public utility::NodeIterWithWorldMatrix {
  public:
    IterWithWorldMatrix(node::Node* node) : utility::NodeIterWithWorldMatrix(node, [](node::Node* node) { return interaction::node_cast<InteractionNode*>(node)->getParent(); }) {
    }
  };

private:
  Page page_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_;
  Creation creation_;
  InteractionPath hover_;

  void appendToContainer(node::Node* child) {
    appendChild(&page_, child);
  }

  void updateSelection();
  void handleHover();
  void onEvent(event::Event& event) override;
  // void onBeforeTick(event::Event* event) override;
  void onMouseWheel(event::MouseEvent& event) override;
  void onMouseDrag(event::MouseEvent& event) override;
  void onWindowResize(event::Event& event) override;
  void onBeforeRender(event::Event& event) override;
  void onAfterTick(event::Event& event) override;
};

} // namespace interaction