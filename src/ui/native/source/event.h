#pragma once

#include "SDL_events.h"
#include "SDL_mouse.h"
#include "desaina.h"
#include <iostream>
#include "core/source/function/event_system/event.h"
#include "event_system/ui_event.h"

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

inline void bindEvents(Desaina& desaina) {
  desaina.addEventListener(EventType::kSetCursor, [](Event* event) {
    auto cursorEvent = static_cast<UIEvent*>(event);
    auto cursor = cursorEvent->cursorType;
    SDL_Cursor* sdlCursor;
    switch (cursor) {
      case CursorType::kSIZEWE: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
        break;
      }
      case CursorType::kSIZENS: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
        break;
      }
      case CursorType::kSIZENESW: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
        break;
      }
      case CursorType::kSIZENWSE: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);
        break;
      }
      case CursorType::kHandle: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        break;
      }
      case CursorType::kDefault: {
        sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        break;
      };
      default: {
        break;
      }
    }

    SDL_SetCursor(sdlCursor);
  });
}
