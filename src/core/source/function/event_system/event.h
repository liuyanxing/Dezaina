#pragma once

#include "desaina_node.h"
#include <functional>

enum class EventType {
  kNone = 0,
  kWindowClose, kWindowResize, kWindowFocus, kWindowLostFocus, kWindowMoved,
  kAppTick, kAppUpdate, kAppRender,
  kKeyPressed, kKeyReleased, kKeyTyped,
  kMouseDown, kMouseUp, kMouseMove,
  kAny,
};

using Node = BaseNodeMixin;
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

using ListenerFunc = std::function<void(const Event* event)>;
struct EventListener {
  EventType type;
  ListenerFunc func;
};


class Event::Builder {
public:
  Builder(EventType type) {
    event_.type = type;
  };

  Event build() {
    return event_;
  };

private:
  Event event_;
};
