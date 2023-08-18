#pragma once

#include "ui_event.h"

struct MouseEvent : public UIEvent {
  class Builder;
  int button;
  int buttons;
};

class MouseEvent::Builder : public UIEvent::Builder {
public:
  Builder(EventType type) : UIEvent::Builder(type) {};
  Builder& setButton(int button) {
    event_.button = button;
    return *this;
  };
  Builder& setButtons(int buttons) {
    event_.buttons = buttons;
    return *this;
  };
  MouseEvent build() {
    return event_;
  };
private:
  MouseEvent event_;
};
