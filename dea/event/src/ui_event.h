#pragma once

#include "event.h"

namespace dea::event {

struct UIEvent : public Event {
  float x;
  float y;
  float dx;
  float dy;
  float localX;
  float localY;
  float worldX;
  float worldY;
  float worldDx;
  float worldDy;
  float dragDx;
  float dragDy;
};

} // namespace event