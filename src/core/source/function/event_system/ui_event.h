#pragma once

#include "event.h"

struct UIEvent : public Event {
  class Builder;
  float x;
  float y;
  float local_x;
  float local_y;
  float client_x;
  float client_y;
};

class UIEvent::Builder : public Event::Builder {
  public:
    Builder(EventType type) : Event::Builder(type) {};
    Builder& setX(int x) {
      event_.x = x;
      return *this;
    };
    Builder& setY(int y) {
      event_.y = y;
      return *this;
    };
    
    UIEvent build() {
      return event_;
    };
  private:
    UIEvent event_;
};