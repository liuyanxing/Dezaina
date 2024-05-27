#pragma once

#include "event_system/event_emitter.h"
#include "function/nodes/source/frame.h"
#include "interaction_node.h"

class Frame : public FrameNode, public InteractionNode,  public EventEmitter {
  
};