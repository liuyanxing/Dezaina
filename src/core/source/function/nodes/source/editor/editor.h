#include "event_system/event.h"
class Editor {
public:
  virtual void onEvent(const Event* event);
};