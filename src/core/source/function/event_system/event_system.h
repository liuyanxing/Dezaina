#include <vector>
#include "event.h"
#include "mouse_event.h"

class EventConsumer {
public:
  virtual void consumeEvent(const Event& event) = 0;
};

class EventSystem {
public:
  void dispatchMouseEvent(float x, float y, EventType type, int button, int buttons) {
    MouseEvent::Builder builder(type);
    builder.setX(x);
    builder.setY(y);
    builder.setButton(button);
    builder.setButtons(buttons);
    builder.build();
    auto event = builder.finish();
    dispatchEvent(event);
  }

  void dispatchEvent(const Event& event) {
    for (const auto& consumer : consumers_) {
      consumer->consumeEvent(event);
    }
  }

  // make sure consumer exists in the lifetime of the program
  void addConsumer(EventConsumer* consumer) {
    consumers_.push_back(consumer);
  }

private:
  std::vector<EventConsumer*> consumers_;
};