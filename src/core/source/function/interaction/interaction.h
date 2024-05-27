#pragma once

#include "desaina.h"
#include "desaina_node.h"
#include "event_system/event.h"
#include "page.h"
#include "bound_editor.h"

class Interaction {
public:
  explicit Interaction(Desaina* desaina) : desaina_(desaina) {}
private:
  Desaina* desaina_;
  PageNode page_;
  NodePool node_pool_{100};
  BoundEditor bound_editor_{desaina_};

  void handleMouseEvent(Event* event);
  void handleMouseMove(Event* event);
  void handleMouseDown(Event* event);
  void handleMouseUp(Event* event);
};
