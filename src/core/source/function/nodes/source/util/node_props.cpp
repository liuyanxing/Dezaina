#include "base_type.h"
#include "desaina.h"
#include "desaina_node.h"
#include "document.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include "node_props.h"
#include <algorithm>
#include <optional>
#include <stdint.h>

namespace util {
  GeometryWithPaints getFillGeometryWithPaints(const TextNode* node, Desaina* desaina) {
    GeometryWithPaints geometryWithPaints;
    geometryWithPaints.geometry.emplace_back();
    SkPath& path = geometryWithPaints.geometry.back();
    auto& paintsWithRect = geometryWithPaints.paints;

    SkMatrix matrix;
    const auto& textData = node->get_textData();
    const auto& glyphs = textData.get_glyphs();
    const auto& decorations = textData.get_decorations();
    const auto& baselines = textData.get_baselines();
    const auto& styleOverrideTable = textData.get_styleOverrideTable();

    kiwi::ByteBuffer buffer(styleOverrideTable.data(), styleOverrideTable.size());

    kiwi::MemoryPool pool;
    uint32_t count;
    buffer.readVarUint(count);
    auto changes = pool.array<Desaina_Kiwi::NodeChange>(count);
    std::unordered_map<uint32_t, SubTextMixin> map;

    for (auto& change : changes) {
      change.decode(buffer, pool);
      SubTextMixin subText;
      subText.applyChange(change);
      uint32_t styleID = subText.get_styleID();
      map[styleID] = std::move(subText);
    }

    uint32_t lastStyleID = -1;
    uint32_t lastBaseLine = -1;
    std::optional<vector<SkPaint>> lastPaint;
    std::optional<SkRect> rect;
    uint32_t curBaseline = 0;

    for (int i = 0; i < glyphs.size(); i++) {
      auto baseline = baselines[curBaseline];
      if (i > baseline.endCharacter) {
        curBaseline++;
        baseline = baselines[curBaseline];
      }
      auto lineAscentPosition = baseline.position.y - baseline.lineAscent;
      auto lineDescentPosition = baseline.position.y + baseline.lineHeight - baseline.lineAscent;

      auto& glyph = glyphs[i];
      auto fontSize = glyph.fontSize;
      auto advance = glyph.advance * fontSize;
      auto styleID = glyph.styleID;
      auto glyphRect = SkRect::MakeLTRB(glyph.position.x, lineAscentPosition, advance, lineDescentPosition);

      if (lastStyleID != styleID) {
        if (rect.has_value() && lastPaint.has_value()) {
          for (auto paint : lastPaint.value()) {
            paintsWithRect.push_back({paint, rect.value()});
          }
        }
        rect = glyphRect;
        auto& styleOverride = map[styleID]; 
        if (auto& paints = styleOverride.get_fillPaints(); paints.size() > 0) {
          lastPaint = vector<SkPaint>{};
          for (auto& paint : paints) {
            lastPaint->push_back(util::toSkPaint(paint));
          }
        }
      } else {
        rect->join(glyphRect);
      }

      matrix.setScaleTranslate(fontSize, -fontSize, glyph.position.x, glyph.position.y);
      const auto& glyphPath = desaina->document.getGeometry(glyph.commandsBlob)->getPath();
      path.addPath(glyphPath, matrix);

      lastStyleID = styleID;
    }

    SkPath decorationPath;
    for (const auto& decoration : decorations) {
      const auto& rects = decoration.get_rects();
      for (const auto& [x, y, w, h] : rects) {
        decorationPath.addRect(SkRect::MakeXYWH(x, y, w, h));
      }
    }

    path.addPath(decorationPath);

    return geometryWithPaints;
  }

  GeometryWithPaints getFillGeometryWithPaints(const Node* node, Desaina* desaina) {
    if (util::isText(node)) {
      return getFillGeometryWithPaints(static_cast<const TextNode*>(node), desaina);
    }

    GeometryWithPaints geometryWithPaints;
    auto& paths = geometryWithPaints.geometry;
    auto& paintsWithRect = geometryWithPaints.paints;

    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& geometry = shape->get_fillGeometry();
      for (const auto& geo : geometry) {
        paths.push_back(desaina->document.getGeometry(geo.commandsBlob)->getPath());
      }
      paintsWithRect = getFillPaintsWithRect(node);
    }
    return geometryWithPaints;
  }

  GeometryWithPaints getStrokeGeometryWithPaints(const Node* node, Desaina* desaina) {
    GeometryWithPaints geometryWithPaints;
    auto& paths = geometryWithPaints.geometry;
    auto& paintsWithRect = geometryWithPaints.paints;

    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& geometry = shape->get_strokeGeometry();
      for (const auto& geo : geometry) {
        paths.push_back(desaina->document.getGeometry(geo.commandsBlob)->getPath());
      }
      paintsWithRect = getStrokePaintsWithRect(node);
    }
    return geometryWithPaints;
  }
}

