#pragma once

#include "canvas.h"
#include "event_system/event_system.h"

class Desaina;
class RenderSystem: public EventEmitter {
public:
  RenderSystem(Desaina* desaina);
  void tick() {
    // canvas_.tick();
  };

  void bindEvents();

private:
  Canvas canvas_;
  Desaina *desaina_;
};