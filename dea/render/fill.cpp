#include "geometry.h"
#include "node.h"
#include "resource.h"
#include <cassert>
#include "include/core/SkMatrix.h"

namespace dea::render {
using namespace dea::node;
using namespace dea::resource;

GeometryType buildRectangle(node::Vector size, float tl, float tr, float br,
                            float bl) {
  constexpr float raduisRatio = 0.447715521F;
  GeometryType path{};

  const float cr = tl * raduisRatio;

  path.moveTo(0, tl);
  path.cubicTo(0, tl - cr, tl - cr, 0, tl, 0);
  path.lineTo(size.x - tr, 0);
  path.cubicTo(size.x - tr + cr, 0, size.x, tr - cr, size.x, tr);
  path.lineTo(size.x, size.y - br);
  path.cubicTo(size.x, size.y - br + cr, size.x - br + cr, size.y, size.x - br,
               size.y);
  path.lineTo(bl, size.y);
  path.cubicTo(bl - cr, size.y, 0, size.y - bl + cr, 0, size.y - bl);
  path.close();
  return path;
}

GeometryType buildFill(const RectangleNode *node) {
  return buildRectangle(node->getSize(),
                        node->getRectangleTopLeftCornerRadius(),
                        node->getRectangleTopRightCornerRadius(),
                        node->getRectangleBottomRightCornerRadius(),
                        node->getRectangleBottomLeftCornerRadius());
}

GeometryType buildFill(const FrameNode *node) {
  return buildRectangle(node->getSize(),
                        node->getRectangleTopLeftCornerRadius(),
                        node->getRectangleTopRightCornerRadius(),
                        node->getRectangleBottomRightCornerRadius(),
                        node->getRectangleBottomLeftCornerRadius());
}

GeometryType buildFill(const TextNode *node) {
    GeometryType path; 
    SkMatrix matrix;
    const auto& textData = node->getTextData();
    const auto& glyphs = textData.getGlyphs();
    const auto& decorations = textData.getDecorations();
    const auto& baselines = textData.getBaselines();
    const auto& styleOverrideTable = textData.getStyleOverrideTable();

    int32_t curBaseline = -1;
    Baseline baseline{};
    float lineAscentPosition = 0;
    float lineDescentPosition = 0;
    for (int i = 0; i < glyphs.size(); i++) {
        auto& glyph = glyphs[i];
      if (curBaseline == -1 || glyph.position.y != baseline.position.y) {
        curBaseline++;
        baseline = baselines[curBaseline];
        lineAscentPosition = baseline.position.y - baseline.lineAscent;
        lineDescentPosition = baseline.position.y + baseline.lineHeight - baseline.lineAscent;
        const auto [x, y] = baseline.position;
        path.addRect(SkRect::MakeLTRB(x, y - 2, x + baseline.width, y));
      }

      auto fontSize = glyph.fontSize;
      matrix.setScaleTranslate(fontSize, -fontSize, glyph.position.x, glyph.position.y);
      const auto* glyphPath = getOrBuild(glyph.commandsBlob);
      path.addPath(*glyphPath, matrix);
    }

    SkPath decorationPath;
    for (const auto& decoration : decorations) {
      const auto& rects = decoration.getRects();
      for (const auto& [x, y, w, h] : rects) {
        decorationPath.addRect(SkRect::MakeXYWH(x, y, w, h));
      }
    }

    path.addPath(decorationPath);

  return path;
}

GeometryType buildFill(NodeConstPtr node) {
  if (auto* rectangle = node_cast<const RectangleNode>(node)) {
    return buildFill(rectangle);
  } else if (auto* frame = node_cast<const FrameNode>(node)) {
    return buildFill(frame);
  }
  return GeometryType{};
}

GeometryType getOrBuildFill(NodeConstPtr node) {
  if (auto* text = node_cast<const TextNode>(node)) {
    return buildFill(text);
  }
  auto *shapeNode = node::node_cast<const DefaultShapeNode>(node);
  if (shapeNode) {
    if (auto &pathes = shapeNode->getFillGeometry(); !pathes.empty()) {
      return *getOrBuild(pathes.front().commandsBlob);
    }
  }
  return GeometryType{};
}

} // namespace dea::render
