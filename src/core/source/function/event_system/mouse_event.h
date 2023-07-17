#include "ui_event.h"

struct MouseEvent : public UIEvent {
  class Builder : public UIEvent::Builder {
    public:
      Builder(EventType type) : UIEvent::Builder(type) {};
  };
  int button;
  int buttons;
};