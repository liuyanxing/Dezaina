#include "document.h"
#include "event_system/event.h"
#include "event_system/mouse_event.h"

class EventHandler {
public:
  EventHandler(Document* document): document_(document) {};

  void onEvent(const Event* event) {
    // 算出hit test node，local坐标，容器包含caption
    completeMouseEvent(this, event);
    handleEvent(event);
  };

  void handleEvent(const Event* event) {
    if (event->type == EventType::kMouseMove) {
      onMouseMove(static_cast<const MouseEvent*>(event));
    } else if (event->type == EventType::kMouseDown) {
      onMouseDown(static_cast<const MouseEvent*>(event));
    } else if (event->type == EventType::kMouseUp) {
      onMouseUp(static_cast<const MouseEvent*>(event));
    }
  };

  virtual void onMouseMove(const MouseEvent* event) = 0;
  virtual void onMouseDown(const MouseEvent* event) = 0;
  virtual void onMouseUp(const MouseEvent* event) = 0;
  Document* document_;
};