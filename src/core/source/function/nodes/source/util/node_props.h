#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkRect.h"
#include "node_type.h"
#include "page.h"
#include "skia.h"
#include <optional>

struct PaintWithRect {
  SkPaint paint;
  std::optional<SkRect > rect;
};

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

  inline vector<PaintWithRect> getFillPaintsWithRect(const Node* node) {
    vector<PaintWithRect> paintsWithRect;
    if (util::isText(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      const auto& [w, h] = shape->get_size();

      auto& paints = shape->get_fillPaints();
      for (auto& paint : paints) {
        paintsWithRect.push_back({util::toSkPaint(paint), SkRect::MakeWH(w, h)});
      }
    } else if (util::isDefaultShapeNode(node)) {

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
}