#pragma once

#include "event_system/event_emitter.h"
#include "include/core/SkPath.h"
#include "interaction_node.h"
#include "vector.h"

class InteractionPath : public VectorNode, public InteractionNode,  public EventEmitter {
public:
  void setPath(const SkPath& path);
  void clearPath();
};