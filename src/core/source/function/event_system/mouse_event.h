#pragma once

#include "ui_event.h"

struct MouseEvent : public UIEvent {
  class Builder;
  int button;
  int buttons;
};

class MouseEvent::Builder : public UIEvent::Builder {
public:
  Builder(EventType type, bool isOwned = true) : UIEvent::Builder(type, false) {
    isOwned_ = isOwned;
    if (isOwned_) {
      event_ = new MouseEvent();
      UIEvent::Builder::setEventRef(event_);
    }
  };
  ~Builder() {
    if (isOwned_) {
      delete event_;
    }
  };
  MouseEvent setEventRef(MouseEvent* event) {
    UIEvent::Builder::setEventRef(event);
    event_ = event;
    return *event_;
  };

  Builder& setButton(int button) {
    event_->button = button;
    return *this;
  };

  Builder& setButtons(int buttons) {
    event_->buttons = buttons;
    return *this;
  };
  MouseEvent build() {
    return *event_;
  };
private:
  MouseEvent* event_;
  bool isOwned_ = true;
};
