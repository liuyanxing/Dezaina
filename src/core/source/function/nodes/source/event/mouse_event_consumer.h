#include "mouse_event_emmiter.h"
#include "simple_hit_tester.h"

class MouseEventConsumer : public MouseEventEmmiter {
public:
  void dispatchEvent(MouseEvent) {

  }
private:
  SimpleHitTester hitTester_;
};
