#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "document.h"
#include "event_system/event_system.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include "kiwi.h"
#include "node_type.h"
#include "page.h"
#include "skia.h"
#include <optional>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <utility>
#include "text.h"

struct PaintWithRect {
  SkPaint paint;
  std::optional<SkRect > rect;
};

struct GeometryWithPaints {
  vector<SkPath> geometry;
  vector<PaintWithRect> paints;
};

class Desaina;
class Geometry;


namespace util {
  inline auto getTransfromMatrix(const Node* node) {
    if (util::isPage(node)) {
      return static_cast<const PageNode*>(node)->getViewMatrix();
    }
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return util::toSkMatrix(shape->get_transform());
    }
    return SkMatrix::I();
  }

  inline void getTextDataFillPaints(TextNode* node, vector<PaintWithRect>& paintsWithRect) {
    TextNodeMixin* textNodeMixin = static_cast<TextNodeMixin*>(node);
    auto& styleOverrideTable = node->get_textData().get_styleOverrideTable();
    kiwi::ByteBuffer buffer(styleOverrideTable.data(), styleOverrideTable.size());

    kiwi::MemoryPool pool;
    uint32_t count;
    buffer.readVarUint(count);
    auto changes = pool.array<Desaina_Kiwi::NodeChange>(count);
    std::unordered_map<uint32_t, vector<SkPaint>> map;

    for (auto& change : changes) {
      change.decode(buffer, pool);
      TextNodeMixin subText = *textNodeMixin;
      subText.applyChange(change);
      uint32_t styleID = 0;
      map[styleID] = {};
      vector<SkPaint>& paints = map[styleID];
      for (auto& paint : subText.get_fillPaints()) {
        paints.push_back(util::toSkPaint(paint));
      }
    }
  }

  inline vector<PaintWithRect> getFillPaintsWithRect(const Node* node) {
    vector<PaintWithRect> paintsWithRect;
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& [w, h] = shape->get_size();

      auto& paints = shape->get_fillPaints();
      for (auto& paint : paints) {
        paintsWithRect.push_back({util::toSkPaint(paint), SkRect::MakeWH(w, h)});
      }
    }
    return paintsWithRect;
  }

  inline vector<PaintWithRect> getStrokePaintsWithRect(const Node* node) {
    vector<PaintWithRect> paintsWithRect;
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);

      auto& paints = shape->get_strokePaints();
      for (auto& paint : paints) {
        paintsWithRect.push_back({util::toSkPaint(paint), std::nullopt});
      }
    }
    return paintsWithRect;
  }
  inline auto getParent(const Node* node, Document* document) {
    auto parent = document->getNodeById(node->get_parentIndex().guid);
    return parent;
  }

  inline string idToString(Node *node) {
    const auto& id = node->get_guid();
    return std::to_string(id.sessionID) + ":" + std::to_string(id.localID);
  }

  void getFillGeometryWithPaints(const TextNode* node, GeometryWithPaints&, Desaina* desaina);
  GeometryWithPaints getFillGeometryWithPaints(const Node* node, Desaina* desaina);
  GeometryWithPaints getStrokeGeometryWithPaints(const Node* node, Desaina* desaina);
  Geometry getHoverGeometry(const Node* node, Desaina* desaina);
}
