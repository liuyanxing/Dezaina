#pragma once

#include "node.h"
#include "event.h"
#include "interaction_node.h"

namespace dea::interaction {

class InteractionPath : public node::VectorNode, public InteractionNode,  public event::EventEmitter {
public:
  void clearPath();
};

}