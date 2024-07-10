#pragma once

#include <optional>
#include <stdint.h>
#include "base_type.h"
#include "event.h"
#include "event_system/listener.h"
#include "mouse_event.h"
#include "system/system.h"

class Desaina;

class EventSystem : public System {
public:
  EventSystem(Desaina* desaina) : desaina_(desaina) {};

  void dispatchMouseEvent(float x, float y, EventType type, int button, int buttons);
  void dispatchWindowResizeEvent(int width, int height, float devicePixelRatio);

  void dispatchUIEvent(UIEvent& event);
  void dispatchEvent(Event& event);

  void clearEvents() {
    for (auto* event : events_) {
      delete event;
    }
    events_.clear();
  }

  void addListener(Listener* listener) {
    listeners_.push_back(listener);
  }

  void tick() override;

private:
  Desaina* desaina_;
  std::optional<MouseEvent> lastMouseEvent_ = std::nullopt;
  float mouseDeltaX_ = 0;
  float mouseDeltaY_ = 0;
  vector<Event*> events_;
  uint32_t lastMouseDownFrame_ = 0;
  vector<Listener*> listeners_;
};
