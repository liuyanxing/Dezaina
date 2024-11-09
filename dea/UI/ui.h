#pragma once

#include "primitives.h"

namespace dea::ui {

struct Position {
  float x;
  float y;
  float rotation;
};

struct Layout {
  float width;
  float height;
};

struct Appearance {
  bool visibility;
  float opacity;
  float cornerRadius[4];
};

struct Fill {
};

struct Stroke {
};

struct Data {
  Position position;
  Layout layout;
  Appearance appearance;
  Fill fill;
  Stroke stroke;
};

class UI {
friend class Interaction;
public:
  static void setCursor(CursorType type);
  const Data &getData() const { return data_; }
private:
  static inline Data data_;
};

} // namespace ui
