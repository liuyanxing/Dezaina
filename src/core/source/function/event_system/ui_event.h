#pragma once

#include "event.h"

struct UIEvent : public Event {
  class Builder;
  float x;
  float y;
  float localX;
  float localY;
  float clientX;
  float clientY;
  float windowWidth;
  float windowHeight;
  float windowX;
  float windowY;
  float mouseDeltaX;
  float mouseDeltaY;
  float devicePixelRatio;
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
    Builder& setMouseDeltaX(int deltaX) {
      event_.mouseDeltaX = deltaX;
      return *this;
    };
    Builder& setMouseDeltaY(int deltaY) {
      event_.mouseDeltaY = deltaY;
      return *this;
    };
    
    UIEvent build() {
      return event_;
    };
  private:
    UIEvent event_;
};