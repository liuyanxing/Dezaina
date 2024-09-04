#pragma once

#include <memory>
#include "creation.h"
#include "event.h"
#include "listener.h"
#include "node.h"
#include "node_editor.h"
#include "selection.h"
#include "node/path.h"
#include "node/page.h"
#include "document.h"

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  Interaction(document::Document& doc);

  auto* root() { return &page_; }
  auto& getNodeEditor() { return node_editor_; }

  void dump();

  static node::Size GetItersectBound(node::Vector size);

private:
  Page page_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_{GetItersectBound, IterWithWorldMatrix{nullptr}};
  Creation creation_;
  document::Document& doc_;

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