#pragma once

#include "event.h"

namespace dea::event {

struct UIEvent : public Event {
  float clientX;
  float clientY;
  float worldX;
  float worldY;
  float dx = 0;
  float dy = 0;
  float dragDx = 0;
  float dragDy = 0;
  float screenLocalX;
  float screenLocalY;
};

} // namespace event