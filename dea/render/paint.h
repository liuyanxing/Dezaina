#pragma once

#include <variant>
#include <vector>
#include "include/core/SkCanvas.h"
#include "include/core/SkPaint.h"
#include "node/include/node.h"
#include "node/node_base.generated.h"
#include "utility.h"

namespace dea::render {

class PaintDrawer {
public:
  void setRegion(const node::Rect& region) {
    region_ = region;
  }
private:
  node::Rect region_;
};

class SolidPaintDrawer : public PaintDrawer {
public:
  SolidPaintDrawer(const node::SolidPaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) const {
    canvas->drawColor(toSkColor(paint_.color));
  }
private:
  node::SolidPaint paint_;
};

class GradientPaintDrawer : public PaintDrawer {
public:
  GradientPaintDrawer(const node::GradientPaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) const {
  }
private:
  node::GradientPaint paint_;
};

class ImagePaintDrawer : public PaintDrawer {
public:
  ImagePaintDrawer(const node::ImagePaint& paint) : paint_{paint} {}
  void draw(SkCanvas* canvas) const {
  }
private:
  node::ImagePaint paint_;
};

using PaintDrawers = std::vector<std::variant<SolidPaintDrawer, GradientPaintDrawer, ImagePaintDrawer>>;

PaintDrawers& buildFillPaintDrawers(node::NodeConstPtr node);
PaintDrawers& buildStrokePaintDrawers(node::NodeConstPtr node);

} // namespace dea::render