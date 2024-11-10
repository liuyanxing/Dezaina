#include "UI/ui.h"
#include <SDL2/SDL.h>

namespace dea::ui {
void UI::setCursor(CursorType type) {
  SDL_Cursor *sdlCursor;
  switch (type) {
  case CursorType::SIZEWE: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
    break;
  }
  case CursorType::SIZENS: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
    break;
  }
  case CursorType::SIZENESW: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
    break;
  }
  case CursorType::SIZENWSE: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);
    break;
  }
  case CursorType::Handle: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    break;
  }
  case CursorType::Default: {
    sdlCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    break;
  };
  default: {
    break;
  }
  }

  SDL_SetCursor(sdlCursor);
}
} // namespace ui
