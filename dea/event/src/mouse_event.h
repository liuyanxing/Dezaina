#pragma once

#include "event.h"
#include "primitives.h"
#include "ui_event.h"

namespace dea::event {

struct MouseEvent : public UIEvent {
  int button;
  int buttons;
  static auto Make(float x, float y, EventType type, int button, int buttons) {
    MouseEvent event;
    event.clientX = x;
    event.clientY = y;
    event.type = type;
    event.button = button;
    event.buttons = buttons;
    return event;
  }
};

inline bool isMouse(Event& event) {
  return static_cast<int>(event.type) <= static_cast<int>(EventType::MouseDown) &&
    static_cast<int>(event.type) >= static_cast<int>(EventType::MouseWheel);
}

} // namespace event