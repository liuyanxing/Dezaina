#include "event.h"

struct UIEvent : public Event {
  class Builder : public Event::Builder {
    public:
      Builder(EventType type) : Event::Builder(type) {};
      Builder& setX(int x) {
        event_.x = x;
        return *this;
      };
      Builder& setY(int y) {
        event_.y = y;
        return *this;
      };
      
      void build() {

      };
  };
  int x;
  int y;
};