#pragma once

#include <optional>
#include <stdint.h>
#include <vector>
#include "base_type.h"
#include "event.h"
#include "mouse_event.h"
#include "event_emitter.h"
#include "system/system.h"

class Desaina;

class EventSystem : public System {
public:
  EventSystem(Desaina* desaina) : desaina_(desaina) {};

  void dispatchMouseEvent(float x, float y, EventType type, int button, int buttons);
  void dispatchWindowResizeEvent(int width, int height, float devicePixelRatio);

  void dispatchUIEvent(UIEvent& event);
  void dispatchEvent(Event& event);

  void clear() {
    for (auto* event : events_) {
      delete event;
    }
    events_.clear();
  }

private:
  Desaina* desaina_;
  std::optional<MouseEvent> lastMouseEvent_ = std::nullopt;
  float mouseDeltaX_ = 0;
  float mouseDeltaY_ = 0;
  vector<Event*> events_;
};
