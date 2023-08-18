#pragma once

#include <optional>
#include <stdint.h>
#include <vector>
#include "event.h"
#include "mouse_event.h"
#include "event_emitter.h"

class Desaina;

class EventSystem {
public:
  EventSystem(Desaina* desaina) : desaina_(desaina) {};

  void dispatchMouseEvent(float x, float y, EventType type, int button, int buttons);
  void dispatchWindowResizeEvent(int width, int height, float devicePixelRatio);

  void dispatchUIEvent(UIEvent& event);
  void dispatchEvent(const Event& event);

private:
  Desaina* desaina_;
  std::optional<MouseEvent> lastMouseEvent_ = std::nullopt;
  float mouseDeltaX_ = 0;
  float mouseDeltaY_ = 0;
};