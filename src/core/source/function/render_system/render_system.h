#include "canvas.h"

class Desaina;
class RenderSystem {
public:
  RenderSystem(Desaina* desaina) : desaina_(desaina), canvas_(desaina) {};
  ~RenderSystem();
  void tick() {
    canvas_.tick();
  };

private:
  Canvas canvas_;
  Desaina *desaina_;
};