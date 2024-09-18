#pragma once

namespace dea::event {

enum class EventType {
  Initialized,
  MouseMove,
  MouseDown,
  MouseUp,
  MouseDrag,
  MouseWheel,
  KeyDown,
  KeyUp,
  KeyPress,
  ViewportChange,
  PageChange,
  BeforeTick,
  AfterTick,
  NextTick,
  AfterFlushed,
  Any,
};

}