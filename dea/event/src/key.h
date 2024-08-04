#pragma once

#include "event.h"
#include "primitives.h"
#include <stdint.h>

namespace dea::event {

using KeyCode = int32_t;

enum class Key {
  Unknown = 0,

  Return = '\r',
  Escape = '\x1B',
  Backspace = '\b',
  Tab = '\t',
  Space = ' ',
  Exclaim = '!',
  QuoteDbl = '"',
  Hash = '#',
  Percent = '%',
  Dollar = '$',
  Ampersand = '&',
  Quote = '\'',
  LeftParen = '(',
  RightParen = ')',
  Asterisk = '*',
  Plus = '+',
  Comma = ',',
  Minus = '-',
  Period = '.',
  Slash = '/',
  _0 = '0',
  _1 = '1',
  _2 = '2',
  _3 = '3',
  _4 = '4',
  _5 = '5',
  _6 = '6',
  _7 = '7',
  _8 = '8',
  _9 = '9',
  Colon = ':',
  Semicolon = ';',
  Less = '<',
  Equals = '=',
  Greater = '>',
  Question = '?',
  At = '@',

  // Uppercase letters are skipped as per the original enum

  LeftBracket = '[',
  Backslash = '\\',
  RightBracket = ']',
  Caret = '^',
  Underscore = '_',
  Backquote = '`',
  a = 'a',
  b = 'b',
  c = 'c',
  d = 'd',
  e = 'e',
  f = 'f',
  g = 'g',
  h = 'h',
  i = 'i',
  j = 'j',
  k = 'k',
  l = 'l',
  m = 'm',
  n = 'n',
  o = 'o',
  p = 'p',
  q = 'q',
  r = 'r',
  s = 's',
  t = 't',
  u = 'u',
  v = 'v',
  w = 'w',
  x = 'x',
  y = 'y',
  z = 'z',
};


struct KeyEvent : public Event {
  KeyCode code;
  
  static auto Make(EventType type, KeyCode keyCode, KeyMode mode) {
    KeyEvent event;
    event.type = type;
    event.code = keyCode;
    event.mode = mode;
    return event;
  }
};

inline bool isKey(const Event& event) {
  return static_cast<int>(event.type) >= static_cast<int>(EventType::KeyDown) &&
    static_cast<int>(event.type) <= static_cast<int>(EventType::KeyPress);
}

} // namespace event