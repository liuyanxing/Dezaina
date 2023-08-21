#pragma once

#include "canvas.h"
#include "system/system.h"

class Desaina;
class RenderSystem: public System {
public:
  RenderSystem(Desaina* desaina);
  void tick() {
    canvas_.tick();
  };

  void bindEvents();

private:
  Canvas canvas_;
  Desaina *desaina_;
};