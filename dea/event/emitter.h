#pragma once

#include <functional>
#include <vector>

#include "event.h"

namespace dea::event {

using ListenerFunc = std::function<void(Event &event)>;
struct EventListener {
  EventType type;
  ListenerFunc func;
  bool once = false;
  bool shouldRemove = false;
};

class EventEmitter {
public:
  void emit(Event &event) {
    for (auto &consumer : consumers_) {
      if (consumer.type == event.type || consumer.type == EventType::Any) {
        consumer.func(event);
        if (consumer.once) {
          consumer.shouldRemove = true;
        }
      }
    }
    consumers_.erase(std::remove_if(consumers_.begin(), consumers_.end(),
                                    [](const EventListener &listener) {
                                      return listener.shouldRemove;
                                    }),
                     consumers_.end());
  }

  void addEventListener(const EventType &type, const ListenerFunc &func,
                        bool once = false) {
    consumers_.push_back({type, func, once});
  }

  virtual ~EventEmitter() = default;

private:
  std::vector<EventListener> consumers_;
};

} // namespace dea::event
