#include "text.h"

SkPath TextNode::getFillGeometry() {
}

SkPath TextNode::getStrokeGeometry() {
  SkPath path;
  path.addRect(SkRect::MakeXYWH(0, 0, 100, 100));
  return path;
}