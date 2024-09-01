#pragma once

#include "event.h"

namespace dea::event {

class Listener {
public:
	virtual void onEvent(Event& event) = 0;
};

class SystemHookListener : public Listener {
public:
  virtual void onEvent(Event& e) override {
    switch (e.type) {
      case EventType::Initialized:
        onInitialized(e);
        break;
      case EventType::BeforeRender:
        onBeforeRender(e);
        break;
      case EventType::BeforeTick:
        onBeforeTick(e);
        break;
      case EventType::AfterTick:
        onAfterTick(e);
        break;
      default:
        break;
    }
  }
private:
  virtual void onInitialized(Event& event) {};
  virtual void onBeforeTick(Event& event) {};
  virtual void onAfterTick(Event& event) {};
  virtual void onBeforeRender(Event& event) {};
};

}