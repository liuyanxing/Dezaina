#pragma once

#include "event.h"

namespace dea::event {

struct MouseEvent : public Event {
  int button;
  int buttons;
};

} // namespace event