#include "event.h"

class MouseEventEmmiter {
public:
  template<typename T>
  void addEventListener() {}

  template<>
  void addEventListener<MouseEvent>(std::function<void(MouseEvent)> func) {
    mouseEventListeners_.push_back(func);
  }
};