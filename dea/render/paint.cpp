#include "paint.h"
#include <variant>

namespace dea::render {

static PaintDrawers paintDrawers{};
static PaintDrawers strokeDrawers{};

static void pushPaintDrawer(const node::SolidPaint& paint) {
  paintDrawers.push_back(SolidPaintDrawer{paint});
}

static void pushPaintDrawer(const node::GradientPaint& paint) {
  paintDrawers.push_back(GradientPaintDrawer{paint});
}

static void pushPaintDrawer(const node::ImagePaint& paint) {
  paintDrawers.push_back(ImagePaintDrawer{paint});
}

void buildPaintDrawers(const std::vector<node::PaintUnion>& paints) {
  paintDrawers.clear();
  paintDrawers.reserve(20);
  for (const auto& paint : paints) {
    std::visit([](auto&& p) {
      pushPaintDrawer(p);
    }, paint);
  }
}

PaintDrawers& buildFillPaintDrawers(node::NodeConstPtr node) {
  auto* shapeNode = node::node_cast<const node::DefaultShapeNode>(node);
  buildPaintDrawers(shapeNode->getFillPaints());
  return paintDrawers;
}

PaintDrawers& buildStrokePaintDrawers(node::NodeConstPtr node) {
  auto* shapeNode = node::node_cast<const node::DefaultShapeNode>(node);
  buildPaintDrawers(shapeNode->getStrokePaints());
  return paintDrawers;
}

} // namespace dea::render