#pragma once

#include "desaina_node.h"
#include "document.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include "include/core/SkSize.h"
#include "node_type.h"
#include "util/node_props.h"
#include "util/skia.h"

namespace util {
// todo : fill path and stroke path bound
  inline SkRect getGeometryBound(const Node* node) {
    if (util::isPage(node)) {
      return SkRect::MakeEmpty();
    }
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return SkRect::MakeIWH(shape->get_size().x, shape->get_size().y);
    }
    return SkRect::MakeEmpty();
  }

  inline SkRect getLocalBound(const Node* node) {
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return SkRect::MakeIWH(shape->get_size().x, shape->get_size().y);
    }
    return SkRect::MakeEmpty();
  }

  inline Vector getSize(const Node* node) {
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return shape->get_size();
    }
    return Vector{0, 0};
  }

  inline bool isPointInNodeGeometry(Node* node, float x, float y) {
    auto size = getGeometryBound(node);
    auto rect = SkRect::MakeIWH(size.width(), size.height());
    return rect.contains(x, y);
  }
  inline auto getWorldMatrix(const Node* node, Document* document) {
    auto matrix = util::getTransfromMatrix(node);
    auto parent = util::getParent(node, document);
    while (parent.has_value()) {
      if (util::isPage(parent.value())) {
        break;
      }
      matrix.preConcat(util::getTransfromMatrix(parent.value()));
      parent = util::getParent(parent.value(), document);
    }
    return matrix;
  }

  inline auto getWorldAABBBound(const Node* node, Document* document) {
    auto matrix = getWorldMatrix(node, document);
    auto bound = getLocalBound(node);
    return matrix.mapRect(bound);
  }

  inline const IVector<Path>& getFillGeometry(const Node* node) {
    static IVector<Path> empty;
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return shape->get_fillGeometry();
    }
    return empty;
  }

  SkPath buildFillPath(const Node* node);
  Geometry* buildFillGeometry(const Node *node, Desaina *desaina);
}
