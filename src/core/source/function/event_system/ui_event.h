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
    explicit Builder(EventType type, bool isOwned = true): Event::Builder(type, false) {
      isOwned_ = isOwned;
      if (isOwned_) {
        event_ = new UIEvent();
        Event::Builder::setEventRef(event_);
      }
    };
    ~Builder() {
      if (isOwned_) {
        delete event_;
      }
    };

    Builder& setEventRef(UIEvent* event) {
      Event::Builder::setEventRef(event);
      event_ = event;
      return *this;
    };

    Builder& setX(int x) {
      event_->x = x;
      return *this;
    };
    Builder& setY(int y) {
      event_->y = y;
      return *this;
    };
    Builder& setMouseDeltaX(int deltaX) {
      event_->mouseDeltaX = deltaX;
      return *this;
    };
    Builder& setMouseDeltaY(int deltaY) {
      event_->mouseDeltaY = deltaY;
      return *this;
    };
    
    UIEvent build() {
      return *event_;
    };
  private:
    UIEvent* event_;
    bool isOwned_ = true;
};