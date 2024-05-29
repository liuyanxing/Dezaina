#pragma once

#include "desaina_node.h"
#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "event_system/mouse_events_consumer.h"
#include "interaction/node/path.h"
#include "node_pool.h"
#include "page.h"
#include "node_editor.h"
#include "system/system.h"
#include "util.h"
#include "selection.h"
#include <memory>

class Interaction : public System, public EventsConsumer {
public:
  explicit Interaction(Desaina* desaina) : EventsConsumer(this), desaina_(desaina), util(desaina), selection_(this) {
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

  void bindEvents();
  void handleSelection();
  void handleHover();
  void handleMouseMove(MouseEvent* event) override {};
  void handleMouseDown(MouseEvent* event) override {};
  void handleMouseUp(MouseEvent* event) override {};
  void handleMouseEvent(MouseEvent* event) override;
  void handleMouseWheel(MouseEvent* event) override;
  void handleWindowResize(Event* event) override;
};
