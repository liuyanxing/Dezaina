#pragma once

#include "primitives.h"
#include <cstdint>
#include "node.h"


namespace dea::event {

using KeyMode = uint32_t;

enum class Keymod {
    None = 0x0000,
    LShift = 0x0001,
    RShift = 0x0002,
    LCtrl = 0x0040,
    RCtrl = 0x0080,
    LAlt = 0x0100,
    RAlt = 0x0200,
    LGui = 0x0400,
    RGui = 0x0800,
    Num = 0x1000,
    Caps = 0x2000,
    Mode = 0x4000,
    Scroll = 0x8000,

    Ctrl = LCtrl | RCtrl,
    Shift = LShift | RShift,
    Alt = LAlt | RAlt,
    GUI = LGui | RGui,

    Reserved = Scroll // 用于与SDL 2.0.0保持源代码兼容性
};


struct Event {
  Event() = default;
  Event(EventType type) : type(type) {}
  EventType type;  
  KeyMode mode;
  dea::node::Node* target = nullptr;
  void stop() {
    isStop_ = true;
  }
  bool isStop() const {
    return isStop_;
  }

  template<Keymod Mod>
  bool isPressed() {
      return (mode & static_cast<KeyMode>(Mod)) != 0;
  }

private:
  bool isStop_ = false;

};

}