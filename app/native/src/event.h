#pragma once

#include "SDL_events.h"
#include "SDL_mouse.h"
#include "dezaina.h"
#include <iostream>

using namespace dea;

inline void processMouseEvent(Dezaina& desaina, SDL_Event& sdlEvent) {
  if (!desaina.getDocument().loaded()) {
    return;
  }
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  auto type = sdlEvent.type;

  switch (type) {
    case SDL_MOUSEWHEEL: {
      auto deltaX = sdlEvent.wheel.x;
      auto deltaY = sdlEvent.wheel.y;
      // std::cout << "mouse wheel" << std::endl;
      desaina.dispatchMouseEvent(
        deltaX,
        deltaY,
        event::EventType::MouseWheel,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEBUTTONDOWN: {
      // std::cout << "mouse down" << std::endl;
      desaina.dispatchMouseEvent(
        mouseX,
        mouseY,
        event::EventType::MouseDown,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEBUTTONUP: {
      // std::cout << "mouse up" << std::endl;
      desaina.dispatchMouseEvent(
        mouseX,
        mouseY,
        event::EventType::MouseUp,
        0,
        0
      );
      break;
    }
    case SDL_MOUSEMOTION: {
      // std::cout << "mouse move" << std::endl;
      desaina.dispatchMouseEvent(
        mouseX,
        mouseY,
        event::EventType::MouseMove,
        0,
        0
      );
      break;
    }
    case SDL_MULTIGESTURE: {
      // std::cout << "gesture" << std::endl;
      if (fabs(sdlEvent.mgesture.dDist) > 0.001) {
        std::cout << "pinch: " << sdlEvent.mgesture.dDist << std::endl;
        desaina.dispatchMouseEvent(
          sdlEvent.mgesture.dDist,
          0,
          event::EventType::MouseWheel,
          0,
          0
        );
      }
      break;
    }
  }
  
}

inline void bindEvents(Dezaina& desaina) {
  // desaina.addEventListener(EventType::kSetCursor, [](Event* event) {
  //   auto cursorEvent = static_cast<UIEvent*>(event);
  //   auto cursor = cursorEvent->cursorType;
  //   SDL_Cursor* sdlCursor;
  //   switch (cursor) {
  //     case CursorType::kSIZEWE: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
  //       break;
  //     }
  //     case CursorType::kSIZENS: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
  //       break;
  //     }
  //     case CursorType::kSIZENESW: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
  //       break;
  //     }
  //     case CursorType::kSIZENWSE: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);
  //       break;
  //     }
  //     case CursorType::kHandle: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
  //       break;
  //     }
  //     case CursorType::kDefault: {
  //       sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
  //       break;
  //     };
  //     default: {
  //       break;
  //     }
  //   }

  //   SDL_SetCursor(sdlCursor);
  // });
}
