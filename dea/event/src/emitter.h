#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>

#include "event.h"

namespace dea::event {

using ListenerFunc = std::function<void(Event& event)>;
struct EventListener {
  EventType type;
  ListenerFunc func;
};

class EventEmitter {
public:
  void emit(Event& event) {
    for (const auto& consumer : consumers_) {
      if (consumer.type == event.type || consumer.type == EventType::Any) {
        consumer.func(event);
      }
    }
  }

  void addEventListener(const EventType& type, const ListenerFunc& func) {
    consumers_.push_back({type, func});
  }

  virtual ~EventEmitter() = default;

private:
  std::vector<EventListener> consumers_{1};
};

}