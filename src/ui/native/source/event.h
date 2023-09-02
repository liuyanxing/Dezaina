#pragma once

#include "SDL_events.h"
#include "desaina.h"
#include <iostream>
#include "core/source/function/event_system/event.h"

inline void processMouseEvent(Desaina& desaina, SDL_Event& event) {
  if (!desaina.document.isLoaded()) {
    return;
  }
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  auto type = event.type;

  switch (type) {
    case SDL_MOUSEWHEEL: {
      auto deltaX = event.wheel.x;
      auto deltaY = event.wheel.y;
      desaina.eventSystem.dispatchMouseEvent(
        deltaX,
        deltaY,
        EventType::kMouseWheel,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEBUTTONDOWN: {
      desaina.eventSystem.dispatchMouseEvent(
        mouseX,
        mouseY,
        EventType::kMouseDown,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEBUTTONUP: {
      desaina.eventSystem.dispatchMouseEvent(
        mouseX,
        mouseY,
        EventType::kMouseUp,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEMOTION: {
      desaina.eventSystem.dispatchMouseEvent(
        mouseX,
        mouseY,
        EventType::kMouseMove,
        0,
        0
      );
      break;
    }
    case SDL_MULTIGESTURE: {
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
      break;
    }
  }
  
}
