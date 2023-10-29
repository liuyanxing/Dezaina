#pragma once

#include "event.h"
#include "include/core/SkRect.h"
#include "types/cursor.h"

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
  float deltaX = 0;
  float deltaY = 0;
  float localDeltaX = 0;
  float localDeltaY = 0;
  float dragDistanceX = 0;
  float dragDistanceY = 0;
  float devicePixelRatio;
  SkRect activeLocalRect;
  CursorType cursorType;
};

class UIEvent::Builder : public Event::Builder {
  public:
    inline static float activeRectSize = 6;
    explicit Builder(EventType type, bool isOwned = true): Event::Builder(type, false) {
      isOwned_ = isOwned;
      if (isOwned_) {
        event_ = new UIEvent{};
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
    Builder& setClientX(int clientX) {
      event_->clientX = clientX;
      return *this;
    };
    Builder& setClientY(int clientY) {
      event_->clientY = clientY;
      return *this;
    };
    Builder& setMouseDeltaX(int deltaX) {
      event_->deltaX = deltaX;
      return *this;
    };
    Builder& setMouseDeltaY(int deltaY) {
      event_->deltaY = deltaY;
      return *this;
    };
    
    UIEvent build() {
      return *event_;
    };
  private:
    UIEvent* event_;
    bool isOwned_ = true;
};
