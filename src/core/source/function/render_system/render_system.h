#pragma once

#include "canvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkRefCnt.h"
#include "system/system.h"

class Desaina;
class RenderSystem: public System {
public:
  RenderSystem(Desaina* desaina);
  ~RenderSystem() {
    free(pixes_);
  };
  void tick() {
    canvas_.tick();
  };

  SkColor readColorAtPointOfNode(const Node* node, float x, float y, const vector<SkPaint>& paints);

  void bindEvents();

private:
  Canvas canvas_;
  sk_sp<SkSurface> read_color_surface_;
  Desaina *desaina_;
  uint8_t* pixes_;
};
