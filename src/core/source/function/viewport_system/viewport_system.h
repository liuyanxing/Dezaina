#pragma once

#include "include/core/SkMatrix.h"
#include "system/system.h"

class Desaina;
class ViewPortSystem: public System {
public:
  ViewPortSystem(Desaina* desaina);

  void tick() {};
  void bindEvents();
private:
  Desaina *desaina_;
	SkMatrix viewMatrix_;
	SkMatrix projectionMatrix_;
};