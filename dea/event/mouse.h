#pragma once

#include "event.h"
#include "primitives.h"
#include "ui_event.h"

namespace dea::event {

    struct MouseEvent : public UIEvent {
        MouseEvent() = default;
        MouseEvent(float x, float y) {
            type = EventType::MouseMove;
            this->x = x;
            this->y = y;
        }
        MouseEvent(float x, float y, EventType type) {
            this->x = x;
            this->y = y;
            this->type = type;
        }
        int button;
        int buttons;
        static auto Make(float x, float y, EventType type, int button, int buttons) {
            MouseEvent event;
            event.x = x;
            event.y = y;
            event.type = type;
            event.button = button;
            event.buttons = buttons;
            return event;
        }
    };

inline bool isMouse(const Event& event) {
  return static_cast<int>(event.type) >= static_cast<int>(EventType::MouseMove) &&
    static_cast<int>(event.type) <= static_cast<int>(EventType::MouseWheel);
}

} // namespace event