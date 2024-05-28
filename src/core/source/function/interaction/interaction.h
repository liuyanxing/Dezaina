#pragma once

#include "desaina.h"
#include "desaina_node.h"
#include "event_system/event.h"
#include "interaction/node/path.h"
#include "page.h"
#include "node_editor.h"
#include "system/system.h"
#include "util.h"
#include "selection.h"
#include <memory>

class Interaction : public System {
public:
  explicit Interaction(Desaina* desaina) : desaina_(desaina), util(desaina), selection_(this) {
    page_.appendChild(&hover_);
  }
  InteractionUtil util;

  void tick() override;
  auto* getDezaina() { return desaina_; }
private:
  Desaina* desaina_;
  PageNode page_;
  NodePool node_pool_{100};
  std::unique_ptr<NodeEditor> node_editor_ = nullptr;
  Selection selection_;
  InteractionPath hover_;

  void handleSelection();
  void handleHover();
  void handleMouseEvent(Event* event);
  void handleMouseMove(Event* event);
  void handleMouseDown(Event* event);
  void handleMouseUp(Event* event);
};
