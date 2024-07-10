#pragma once

#include "event_system/event.h"
#include "event_system/mouse_event.h"
#include <cassert>
class Listener {
public:
  virtual void onEvent(Event* event) {
    if (event->isMouseEvent()) {
      auto* mouseEvent = static_cast<MouseEvent*>(event);
      onMouseEvent(mouseEvent);
      switch (event->type) {
        case EventType::kMouseDown:
          onMouseDown(mouseEvent);
          break;
        case EventType::kMouseMove:
          onMouseMove(mouseEvent);
          break;
        case EventType::kMouseUp:
          onMouseUp(mouseEvent);
          break;
        case EventType::kMouseWheel:
          onMouseWheel(mouseEvent);
          break;
        case EventType::kMouseDrag:
          onMouseDrag(mouseEvent);
          break;
        default:
          break;
      }
    } else {
      switch (event->type) {
      case EventType::kWindowResize:
        onWindowResize(event);
        break;
      default:
      case EventType::kBeforeTick:
        onBeforeTick(event);
        break;
      case EventType::kAfterTick:
        onAfterTick(event);
        break;
      }
    }
  }

  virtual ~Listener() = default;
private:
  virtual void onMouseMove(MouseEvent* event) {};
  virtual void onMouseDown(MouseEvent* event) {};
  virtual void onMouseUp(MouseEvent* event) {};
  virtual void onMouseDrag(MouseEvent* event) {};
  virtual void onMouseEvent(MouseEvent* event) {};
  virtual void onMouseWheel(MouseEvent* event) {};
  virtual void onWindowResize(Event* event) {};
  virtual void onBeforeTick(Event* event) {};
  virtual void onAfterTick(Event* event) {};
};
