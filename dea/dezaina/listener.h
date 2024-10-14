#pragma once

#include "event.h"

namespace dea {

class Listener {
public:
  void onEvent(event::Event& e) {
    switch (e.type) {
      case event::EventType::Initialized:
        onInitialized(e);
        break;
      case event::EventType::AfterFlushed:
        onAfterFlushed(e);
        break;
      case event::EventType::BeforeTick:
        onBeforeTick(e);
        break;
      case event::EventType::AfterTick:
        onAfterTick(e);
        break;
      default:
        break;
    }
  }
private:
  virtual void onInitialized(event::Event& event) {};
  virtual void onBeforeTick(event::Event& event) {};
  virtual void onAfterTick(event::Event& event) {};
  virtual void onAfterFlushed(event::Event& event) {};
};

}