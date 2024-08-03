#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>

#include "event.h"

namespace dea::event {

using ListenerFunc = std::function<void(Event& event)>;
struct EventListener {
  EventType type;
  ListenerFunc func;
};

template <size_t Count = 3>
class EventEmitter {
public:
  void emit(Event& event) {
    for (const auto& consumer : consumers_) {
      if (consumer.type == event.type || consumer.type == EventType::Any) {
        consumer.func(&event);
      }
    }
  }

  void addEventListener(const EventType& type, const ListenerFunc& func) {
    consumers_[index_++] = {type, func};
  }

  virtual ~EventEmitter() = default;

private:
  std::array<EventListener, Count> consumers_;
  uint8_t index_ = 0;
};

}