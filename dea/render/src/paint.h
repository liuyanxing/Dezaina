#pragma once

#include <variant>
#include <vector>
#include "include/core/SkCanvas.h"
#include "include/core/SkPaint.h"
#include "node/include/node.h"
#include "node/src/node-base/node.generated.h"
#include "utility/skia.h"

namespace dea::render {

class PaintDrawer {
public:
};

class SolidPaintDrawer : public PaintDrawer {
public:
  SolidPaintDrawer(const node::SolidPaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) {
    canvas->drawColor(utility::toSkColor(paint_.color));
  }
private:
  node::SolidPaint paint_;
};

class GradientPaintDrawer : public PaintDrawer {
public:
  GradientPaintDrawer(const node::GradientPaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) {
  }
private:
  node::GradientPaint paint_;
};

class ImagePaintDrawer : public PaintDrawer {
public:
  ImagePaintDrawer(const node::ImagePaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) {
  }
private:
  node::ImagePaint paint_;
};

using PaintDrawers = std::vector<std::variant<SolidPaintDrawer, GradientPaintDrawer, ImagePaintDrawer>>;

PaintDrawers& buildFillPaintDrawers(const node::Node* node);
PaintDrawers& buildStrokePaintDrawers(const node::Node* node);

} // namespace dea::render