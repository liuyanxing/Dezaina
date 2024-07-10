#pragma once

#include <functional>
#include "node_type.h"

enum class EventType {
  kNone = 0,
  kWindowClose, kWindowResize, kWindowFocus, kWindowLostFocus, kWindowMoved,
  kAppTick, kAppUpdate, kAppRender,
  kKeyDown, kKeyUp,
  kMouseDown, kMouseUp, kMouseMove, kMouseWheel, kMouseDoubleClick, kMouseDrag,
  kViewPortChange, kSelectionChange,
  kSetCursor,
  kEditorChagne,
  kBeforeTick,
  kAfterTick,
  kAny,
};

struct Event {
  EventType type;  
  Node* target = nullptr;
  uint32_t triggeredFrame = 0;
  class Builder;
  bool isMouseEvent() const {
    return isMouseEvent(type);
  }
  void stop() {
    isStop_ = true;
  }
  bool isStop() const {
    return isStop_;
  }

  static bool isMouseEvent(EventType type) {
    return type > EventType::kKeyUp && type < EventType::kViewPortChange;
  }
private:
  bool isStop_ = false;

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
      event_ = new Event{};
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
