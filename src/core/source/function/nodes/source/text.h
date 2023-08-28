#pragma once

#include "desaina_node.h"
#include "include/core/SkColor.h"
#include "include/core/SkPath.h"
#include "base_type.h"

struct ColorRect {
  SkColor color;
  SkRect rect;
};

class TextNode : public TextNodeBase {
public:
  vector<ColorRect> getFillRects();
};