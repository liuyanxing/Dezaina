#pragma once

#include <functional>
#include "node_type.h"

enum class EventType {
  kNone = 0,
  kWindowClose, kWindowResize, kWindowFocus, kWindowLostFocus, kWindowMoved,
  kAppTick, kAppUpdate, kAppRender,
  kKeyPressed, kKeyReleased, kKeyTyped,
  kMouseDown, kMouseUp, kMouseMove, kMouseWheel,
  kViewPortChange,
  kAny,
};

struct Event {
  EventType type;  
  Node* target;
  class Builder;
  bool isMouseEvent() const {
    return isMouseEvent(type);
  }

  static bool isMouseEvent(EventType type) {
    return type == EventType::kMouseDown || type == EventType::kMouseUp || type == EventType::kMouseMove;
  }

};

using ListenerFunc = std::function<void(Event* event)>;
struct EventListener {
  EventType type;
  ListenerFunc func;
};


class Event::Builder {
public:
  Builder(EventType type, bool isOwned = true): type_(type) {
    isOwned_ = isOwned;
    if (isOwned_) {
      event_ = new Event();
      event_->type = type;
    }
  };
  ~Builder() {
    if (isOwned_) {
      delete event_;
    }
  };

  Builder& setEventRef(Event* event) {
    event_ = event;
    event_->type = type_;
    return *this;
  };

  Event build() {
    return *event_;
  };

private:
  Event* event_;
  EventType type_;
  bool isOwned_ = false;
};
