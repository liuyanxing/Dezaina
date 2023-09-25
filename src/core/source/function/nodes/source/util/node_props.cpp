#include "base_type.h"
#include "desaina.h"
#include "desaina_node.h"
#include "document.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include "node_props.h"
#include "util/node_geometry.h"
#include <algorithm>
#include <optional>
#include <stdint.h>

namespace util {
  void getFillGeometryWithPaints(const TextNode* node, GeometryWithPaints& geometryWithPaints, Desaina* desaina) {
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

    int32_t lastStyleID = -1;
    std::optional<vector<SkPaint>> lastPaint;
    std::optional<SkRect> rect;
    int32_t curBaseline = -1;
    Baseline baseline{};

    auto addPaintsWithRect = [&lastPaint, &rect, &paintsWithRect]() {
        if (rect.has_value() && lastPaint.has_value()) {
          for (auto paint : lastPaint.value()) {
            paintsWithRect.push_back({paint, rect.value()});
          }
          lastPaint = std::nullopt;
        }
    };

    float lineAscentPosition = 0;
    float lineDescentPosition = 0;

    for (int i = 0; i < glyphs.size(); i++) {
      auto& glyph = glyphs[i];
      if (curBaseline == -1 || glyph.position.y != baseline.position.y) {
        addPaintsWithRect();
        curBaseline++;
        baseline = baselines[curBaseline];
        lineAscentPosition = baseline.position.y - baseline.lineAscent;
        lineDescentPosition = baseline.position.y + baseline.lineHeight - baseline.lineAscent;
        const auto [x, y] = baseline.position;
        path.addRect(SkRect::MakeLTRB(x, y - 2, x + baseline.width, y));
        rect = std::nullopt;
        lastPaint = std::nullopt;
        lastStyleID = -1;
      }

      auto fontSize = glyph.fontSize;
      auto advance = glyph.advance * fontSize;
      auto styleID = glyph.styleID;
      auto glyphRect = SkRect::MakeLTRB(glyph.position.x, lineAscentPosition, glyph.position.x + advance, lineDescentPosition);

      if (lastStyleID != styleID) {
        addPaintsWithRect();
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
      const auto& glyphPath = util::getGeometryFromBlob(glyph.commandsBlob, desaina).getPath();
      path.addPath(glyphPath, matrix);

      lastStyleID = styleID;
    }
    addPaintsWithRect();

    SkPath decorationPath;
    for (const auto& decoration : decorations) {
      const auto& rects = decoration.get_rects();
      for (const auto& [x, y, w, h] : rects) {
        decorationPath.addRect(SkRect::MakeXYWH(x, y, w, h));
      }
    }

    path.addPath(decorationPath);
  }

  GeometryWithPaints getFillGeometryWithPaints(const Node* node, Desaina* desaina) {
    GeometryWithPaints geometryWithPaints;
    auto& paths = geometryWithPaints.geometry;

    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      geometryWithPaints.paints = getFillPaintsWithRect(node);
    
      if (util::isText(node)) {
        getFillGeometryWithPaints(static_cast<const TextNode*>(node), geometryWithPaints, desaina);
        return geometryWithPaints;
      }
    
      const auto& geometry = shape->get_fillGeometry();
      for (const auto& geo : geometry) {
        paths.push_back(util::getGeometryFromBlob(geo.commandsBlob, desaina).getPath());
      }
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
        paths.push_back(util::getGeometryFromBlob(geo.commandsBlob, desaina).getPath());
      }
      paintsWithRect = getStrokePaintsWithRect(node);
    }
    return geometryWithPaints;
  }

  Geometry getHoverGeometry(const Node* node, Desaina* desaina) {
    Geometry geometry{nullptr};
    if (util::isDefaultShapeNode(node)) {
      if (util::isText(node)) {
      }
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& geo = shape->get_fillGeometry().back();
      return util::getGeometryFromBlob(geo.commandsBlob, desaina);
    }
    return geometry;
  }

  void processInstanceNode(InstanceNode* node, Document& document) {
    auto& symbolData = node->get_symbolData();
    auto& guid = symbolData.get_symbolID();
    auto* symbol = document.getNodeById(guid).value();
  }
}

