#pragma once

#include "creation.h"
#include "event.h"
#include "interaction/node/path.h"
#include "node_pool.h"
#include "page.h"
#include "node_editor.h"
#include "util.h"
#include "selection.h"

namespace dea::interaction {

class Interaction : public InteractionListener {
public:
  explicit Interaction() : InteractionListener(), selection_(), creation_() {
    page_.appendChild(&hover_);
  }

  auto* dezaina() { return desaina_; }
  void onEvent(Event* event) override;
private:
  Dezana& desaina_;
  PageNode page_;
  NodePool node_pool_{100};
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_;
  Creation creation_;
  InteractionPath hover_;

  void updateSelection();
  void handleHover();
  void onBeforeTick(Event* event) override;
  void onAfterTick(Event* event) override;
  void onMouseWheel(MouseEvent* event) override;
  void onWindowResize(Event* event) override;
};

} // namespace interaction