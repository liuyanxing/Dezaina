#pragma once

#include "event_system/event_emitter.h"

class System: public EventEmitter {
public:
  virtual void tick() {};
};