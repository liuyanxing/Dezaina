#pragma once

#include "event.h"
#include "node.h"
#include "interaction_node.h"


namespace dea::interaction {
class Frame : public node::FrameNode, public InteractionNode,  public event::EventEmitter {
  
};

}
