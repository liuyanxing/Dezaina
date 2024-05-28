#pragma once

#include <vector>
#include "event.h"
#include "mouse_event.h"

class EventEmitter {
public:
  void emit(Event& event) {
    for (const auto& consumer : consumers_) {
      if (consumer.type == event.type || consumer.type == EventType::kAny) {
        consumer.func(&event);
      }
    }
  }

  void addEventListener(const EventListener& consumer) {
    consumers_.push_back(consumer);
  }

  void addEventListener(const EventType& type, const ListenerFunc& func) {
    consumers_.push_back({type, func});
  }

  virtual ~EventEmitter() = default;

private:
  std::vector<EventListener> consumers_;
};