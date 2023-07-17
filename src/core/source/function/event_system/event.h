enum class EventType {
  kNone = 0,
  kWindowClose, kWindowResize, kWindowFocus, kWindowLostFocus, kWindowMoved,
  kAppTick, kAppUpdate, kAppRender,
  kKeyPressed, kKeyReleased, kKeyTyped,
  kMouseDown, kMouseUp, kMouseMove,
};

struct Event {
  EventType type;  
  class Builder;
};

class Event::Builder {
public:
  Builder(EventType type) {
    event_.type = type;
  };

  Event finish() {
    return event_;
  };

private:
  Event event_;
};
