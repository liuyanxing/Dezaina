#pragma once

#include <vector>
#include "event.h"
#include "mouse_event.h"

class EventSystem {
public:
  void dispatchEvent(const Event& event) {
    for (const auto& consumer : consumers_) {
      if (consumer.type == event.type) {
        consumer.func(&event);
      }
    }
  }

  void addEventListener(const EventListener& consumer) {
    consumers_.push_back(consumer);
  }

private:
  void dispatchMouseEvent(float x, float y, EventType type, int button, int buttons) {
    MouseEvent::Builder builder(type);
    builder.setX(x);
    builder.setY(y);
    builder.setButton(button);
    builder.setButtons(buttons);
    auto event = builder.build();
    dispatchEvent(event);
  }


  std::vector<EventListener> consumers_;
};