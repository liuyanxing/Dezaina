#pragma once

#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "event_system/mouse_event.h"
#include <cassert>
class EventsConsumer {
public:
  explicit EventsConsumer(EventEmitter* eventEmitter) {
    eventEmitter->addEventListener(EventType::kAny, [this](Event* event) {
      if (event->isMouseEvent()) {
        auto* mouseEvent = static_cast<MouseEvent*>(event);
        handleMouseEvent(mouseEvent);
        switch (event->type) {
          case EventType::kMouseDown:
            handleMouseDown(mouseEvent);
            break;
          case EventType::kMouseMove:
            handleMouseMove(mouseEvent);
            break;
          case EventType::kMouseUp:
            handleMouseUp(mouseEvent);
            break;
          case EventType::kMouseWheel:
            handleMouseWheel(mouseEvent);
            break;
          default:
            break;
        }
      } else {
        switch (event->type) {
        case EventType::kWindowResize:
          handleWindowResize(event);
          break;
        default:
          assert(false);
          break;
        }
      }
    });
  }
  virtual ~EventsConsumer() = default;
private:
  virtual void handleMouseMove(MouseEvent* event) {};
  virtual void handleMouseDown(MouseEvent* event) {};
  virtual void handleMouseUp(MouseEvent* event) {};
  virtual void handleMouseEvent(MouseEvent* event) {};
  virtual void handleMouseWheel(MouseEvent* event) {};
  virtual void handleWindowResize(Event* event) {};
};
