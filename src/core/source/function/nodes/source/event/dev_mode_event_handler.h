#include "event_handler.h"
#include "event_system/event.h"
#include "event_system/mouse_event.h"

class DevModeEventHandler : public EventHandler {
public:
  void onMouseMove(const MouseEvent *event) {
    document_->setHoverNode(event->target);
  }
};