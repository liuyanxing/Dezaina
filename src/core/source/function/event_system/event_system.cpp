#include "desaina.h"
#include "event_system/event.h"
#include "event_system/event_system.h"
#include "event_system/mouse_event.h"
#include "event_system/ui_event.h"
#include <stdint.h>

void EventSystem::tick() {
  const Systems& systems = *desaina_->getSystems();
  for (const auto &system : systems) {
    for (auto* event : events_) {
      if (event->isStop()) {
        continue;
      }
      system->emit(*event);
    }
  }
  clearEvents();
}

void EventSystem::dispatchEvent(Event &event) {
  events_.push_back(&event);
}

void EventSystem::dispatchUIEvent(UIEvent &event) {
  auto point = desaina_->viewPortSystem.mapScreenToWorld(event.clientX, event.clientY);
  event.x = point.x();
  event.y = point.y();
  if (lastMouseEvent_.has_value()) {
    event.deltaX = event.x - lastMouseEvent_->x;
    event.deltaY = event.y - lastMouseEvent_->y;
  }
  dispatchEvent(event);
}

void EventSystem::dispatchMouseEvent(float x, float y, EventType type, int button, int buttons) {
    MouseEvent::Builder builder(type);
    if (type == EventType::kMouseWheel) {
      builder.setMouseDeltaX(x);
      builder.setMouseDeltaY(y);
    } else {
      builder.setClientX(x);
      builder.setClientY(y);
    }
  
    builder.setButton(button);
    builder.setButtons(buttons);
    auto event = builder.build();
  
    if (type == EventType::kMouseMove && lastMouseEvent_.has_value()) {
      auto lastType = lastMouseEvent_->type;
      if (lastType == EventType::kMouseDown || lastType == EventType::kMouseDrag) {
        event.type = EventType::kMouseDrag;
      }
    }
  
    auto* e = new MouseEvent(event);
    dispatchUIEvent(*e);
    lastMouseEvent_ = *e;
}

void EventSystem::dispatchWindowResizeEvent(int width, int height, float devicePixelRatio) {
  desaina_->setWindowInfo({width, height, devicePixelRatio});
  UIEvent::Builder builder(EventType::kWindowResize);
  auto event = builder.build();
  auto* e = new UIEvent(event);
  dispatchUIEvent(*e);
}
