#pragma once

#include <memory>
#include "creation.h"
#include "event.h"
#include "event/src/listener.h"
#include "interaction/src/listener.h"
#include "node_editor.h"
#include "selection.h"
#include "node/path.h"

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  explicit Interaction() {
    page_.appendChild(&hover_);
  }

private:
  node::PageNode page_;
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_;
  Creation creation_;
  InteractionPath hover_;

  void updateSelection();
  void handleHover();
  void onEvent(event::Event& event) override;
  // void onBeforeTick(event::Event* event) override;
  void onAfterTick(event::Event& event) override;
  void onMouseWheel(event::MouseEvent& event) override;
  void onWindowResize(event::Event& event) override;
};

} // namespace interaction