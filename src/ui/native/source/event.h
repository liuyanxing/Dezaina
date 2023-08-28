#pragma once

#include "SDL_events.h"
#include "desaina.h"
#include <iostream>
#include "core/source/function/event_system/event.h"

inline void processMouseEvent(Desaina& desaina, SDL_Event& event) {
  if (!desaina.document.isLoaded()) {
    return;
  }
  int mouse_pos_x, mouse_pos_y;
  SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);

  auto type = event.type;
  
  if (type == SDL_MOUSEWHEEL) {
    auto deltaX = event.wheel.x;
    auto deltaY = event.wheel.y;
    desaina.eventSystem.dispatchMouseEvent(
      deltaX,
      deltaY,
      EventType::kMouseWheel,
      0,
      0
    );
  } else if (type == SDL_MOUSEBUTTONDOWN) {
    std::cout << "mouse down" << std::endl;
  } else if (type == SDL_MOUSEBUTTONUP) {
    std::cout << "mouse up" << std::endl;
  } else if (type == SDL_MOUSEMOTION) {
    std::cout << "mouse move" << std::endl;
  } else if (type == SDL_MULTIGESTURE) {
    std::cout << "gesture" << std::endl;
    if (fabs(event.mgesture.dDist) > 0.001) {
      std::cout << "pinch: " << event.mgesture.dDist << std::endl;
      desaina.eventSystem.dispatchMouseEvent(
        event.mgesture.dDist,
        0,
        EventType::kMouseWheel,
        0,
        0
      );
    }
  } else {
    std::cout << "mouse event: " << type << std::endl;
  }
}
