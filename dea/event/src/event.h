#pragma once

#include "primitives.h"

namespace dea::event {

struct Event {
  EventType type;  
  void stop() {
    isStop_ = true;
  }
  bool isStop() const {
    return isStop_;
  }

private:
  bool isStop_ = false;

};

}