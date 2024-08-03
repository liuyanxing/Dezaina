#pragma once

#include "event.h"

namespace dea::event {

class Listener {
public:
	virtual void onEvent(Event& event) = 0;
};

class SystemHookListener : public Listener {
public:
  virtual void onEvent(Event& event) override {
    switch (event.type) {
      case EventType::BeforeTick:
        onBeforeTick(event);
        break;
      case EventType::AfterTick:
        onAfterTick(event);
        break;
      default:
        break;
    }
  }
private:
  virtual void onBeforeTick(Event& event) {};
  virtual void onAfterTick(Event& event) {};
};

}