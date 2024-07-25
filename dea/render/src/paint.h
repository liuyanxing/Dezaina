#pragma once

#include <variant>
#include <vector>
#include "node/include/node.h"

namespace dea::render {

class PaintDrawer {
public:
	virtual ~PaintDrawer() = default;
};

class SolidPaintDrawer : public PaintDrawer {
public:
  static SolidPaintDrawer build(const node::Node* node);
};

class GradientPaintDrawer : public PaintDrawer {

};

class ImagePaintDrawer : public PaintDrawer {

};

using PaintDrawers = std::vector<std::variant<SolidPaintDrawer, GradientPaintDrawer, ImagePaintDrawer>>;

PaintDrawers& buildFillPaintDrawers(const node::Node* node);
PaintDrawers& buildStrokePaintDrawers(const node::Node* node);

} // namespace dea::render