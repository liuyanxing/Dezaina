#pragma once

#include <memory>
#include "creation.h"
#include "event.h"
#include "event/src/listener.h"
#include "interaction/src/listener.h"
#include "node/src/node-base/node_base.generated.h"
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

  void dump();

  static SkSize GetItersectBound(node::Vector size);

private:
  Page page_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_{GetItersectBound, IterWithWorldMatrix{nullptr}, true};
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
  void onInitialized(event::Event& event) override;
  void onBeforeRender(event::Event& event) override;
  void onAfterTick(event::Event& event) override;
};

} // namespace interaction