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
  float localWorldX;
  float localWorldY;
  float localDx;
  float localDy;
  float localWorldDx;
  float localWorldDy;
  float worldX;
  float worldY;
  float worldDx;
  float worldDy;
  float dragStartX;
  float dragStartY;
};

} // namespace event