#pragma once

namespace dea::event {

enum class EventType {
  MouseMove,
  MouseDown,
  MouseUp,
  MouseDrag,
  MouseWheel,
  KeyDown,
  KeyUp,
  KeyPress,
  ViewportChange,
  BeforeTick,
  AfterTick,
  BeforeRender,
  Any,
};

}