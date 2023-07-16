#include "event.h"

class MouseEventEmmiter {
public:
  void dispatchEvent(MouseEvent) {

  }

  template<typename T>
  void addEventListener() {}

  template<>
  void addEventListener<MouseEvent>(std::function<void(MouseEvent)> func) {
    mouseEventListeners_.push_back(func);
  }

  void addHitTestNode(HitTestNode node) {
    hitTester_.updateChild(node);
  }

private:
  SimpleHitTester hitTester_;
};