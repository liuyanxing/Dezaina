#pragma once

#include "event_system/event_emitter.h"
#include "function/nodes/source/rectangle.h"
#include "interaction_node.h"

class Rectangle : public RectangleNode, public InteractionNode,  public EventEmitter {
  
};