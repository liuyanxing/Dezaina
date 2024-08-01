#pragma once

#include "creation.h"
#include "desaina_node.h"
#include "event_system/listener.h"
#include "interaction/node/path.h"
#include "node_pool.h"
#include "page.h"
#include "node_editor.h"
#include "util.h"
#include "selection.h"

namespace interaction {

class Interaction : public Listener {
public:
  explicit Interaction(Desaina* desaina) : Listener(), desaina_(desaina), util(desaina), selection_(this), creation_(this) {
    page_.appendChild(&hover_);
  }
  InteractionUtil util;

  auto* dezaina() { return desaina_; }
  void onEvent(Event* event) override;
private:
  Desaina* desaina_;
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