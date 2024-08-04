#pragma once

#include "event.h"
#include "primitives.h"
#include <stdint.h>

namespace dea::event {

using KeyCode = int32_t;

struct KeyEvent : public Event {
  KeyCode keyCode;
  
  static auto Make(EventType type, KeyCode keyCode, KeyMode mode) {
    KeyEvent event;
    event.type = type;
    event.keyCode = keyCode;
    event.keyMode = mode;
    return event;
  }
};

inline bool isKey(const Event& event) {
  return static_cast<int>(event.type) >= static_cast<int>(EventType::KeyDown) &&
    static_cast<int>(event.type) <= static_cast<int>(EventType::KeyPress);
}

} // namespace event