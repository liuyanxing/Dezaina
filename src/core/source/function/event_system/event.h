#pragma once

#include <functional>
enum class EventType {
  kNone = 0,
  kWindowClose, kWindowResize, kWindowFocus, kWindowLostFocus, kWindowMoved,
  kAppTick, kAppUpdate, kAppRender,
  kKeyPressed, kKeyReleased, kKeyTyped,
  kMouseDown, kMouseUp, kMouseMove,
};

struct Event {
  EventType type;  
  class Builder;
};

struct EventListener {
  std::function<void(const Event& event)> func;
  EventType type;
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
