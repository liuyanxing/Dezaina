#include "desaina.h"
#include "event_system/event_system.h"
#include "event_system/mouse_event.h"
#include "event_system/ui_event.h"
#include <stdint.h>

void EventSystem::tick() {
  const Systems& systems = *desaina_->getSystems();
  for (const auto &system : systems) {
    for (auto* event : events_) {
      system->emit(*event);
    }
  }
}

void EventSystem::dispatchEvent(Event &event) {
  events_.push_back(&event);
}

void EventSystem::dispatchUIEvent(UIEvent &event) {
  if (lastMouseEvent_.has_value()) {
    event.mouseDeltaX = event.x - lastMouseEvent_->x;
    event.mouseDeltaY = event.y - lastMouseEvent_->y;
  }
  dispatchEvent(event);
}

void EventSystem::dispatchMouseEvent(float x, float y, EventType type, int button, int buttons) {
    MouseEvent::Builder builder(type);
    builder.setX(x);
    builder.setY(y);
    builder.setButton(button);
    builder.setButtons(buttons);
    auto event = builder.build();
    auto* e = new MouseEvent(event);
    dispatchUIEvent(*e);
    lastMouseEvent_ = event;
}

void EventSystem::dispatchWindowResizeEvent(int width, int height, float devicePixelRatio) {
  desaina_->setWindowInfo({width, height, devicePixelRatio});
  UIEvent::Builder builder(EventType::kWindowResize);
  auto event = builder.build();
  auto* e = new UIEvent(event);
  dispatchUIEvent(*e);
}
