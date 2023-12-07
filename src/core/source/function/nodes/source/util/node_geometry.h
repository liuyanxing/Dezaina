#pragma once

#include "base_type.h"
#include "change_system/layouts/layout_node.h"
#include "desaina_node.h"
#include "document.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPath.h"
#include "include/core/SkPoint.h"
#include "include/core/SkRect.h"
#include "include/core/SkSize.h"
#include "node_type.h"
#include "services/blob_service.h"
#include "util/node_props.h"
#include "util/skia.h"
#include "base/math.h"
#include <cmath>
#include <stdint.h>

class Geometry : public BlobAttachment {
public:
  Geometry(const Blob* blob) : commandsBlob(blob) {}
  const SkPath& getPath() {
    if (path.isEmpty()) {
      path = util::toSkPath(commandsBlob->buffer());
    }
    return path;
  }
  void setPath(SkPath&& path) {
    this->path = std::move(path);
  }
  SkPath path;
private:
  const Blob* commandsBlob = nullptr;
};

using CornerRadii = std::array<float, 4>;

template<typename T>
static CornerRadii getCornerRadii(const T* node) {
    Vector size = node->get_size();
    float topLeftRadius = node->get_rectangleTopLeftCornerRadius();
    float topRightRadius = node->get_rectangleTopRightCornerRadius();
    float bottomLeftRadius = node->get_rectangleBottomLeftCornerRadius();
    float bottomRightRadius = node->get_rectangleBottomRightCornerRadius();
    return { topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius};
}

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

  inline void setSize(Node* node, const Vector& size) {
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<DefaultShapeNode*>(node);
      shape->set_size(size);
    }
  }

  inline bool isPointInNodeGeometry(Node* node, float x, float y) {
    auto bound = getGeometryBound(node);
    return bound.contains(x, y);
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

  const IVector<Path>& getFillGeometry(const Node* node);
  const IVector<Path>& getStrokeGeometry(const Node* node);
  const VectorData& getVectorData(const Node* node);
  
  inline CornerRadii getCornerRadii(const Node* node) {
    if (util::isFrame(node)) {
      return getCornerRadii(static_cast<const FrameNode*>(node));
    } else if (util::isRectangle(node)) {
      return getCornerRadii(static_cast<const RectangleNode*>(node));
    }

    return CornerRadii{0, 0, 0, 0};
  }

  inline float getRotation(const Node* node) {
    auto matrix = util::getTransfromMatrix(node);
    return base::getRotation(matrix);
  }

  inline SkVector getTranslate(const Node* node) {
    auto matrix = util::getTransfromMatrix(node);
    auto size = util::getSize(node);
    return matrix.mapPoint({size.x / 2, size.y / 2}) - SkPoint{size.x / 2, size.y / 2};
  }

  inline SkMatrix computeTransform(SkVector translate, float rotation, const Node* node) {
    auto transform = SkMatrix::I();
    auto size = util::getSize(node);

    transform.setRotate(rotation, size.x / 2, size.y / 2);
    transform.postTranslate(translate.x(), translate.y());
    return transform;
  }

  inline void setTransform(Node* node, const Matrix& transform) {
    if (util::isDefaultShapeNode(node)) {
      static_cast<DefaultShapeNode*>(node)->set_transform(transform);
    }
  }

  SkPath buildFillPath(const Node* node);
  BlobPair buildFillGeometry(const LayoutNode *node, Desaina *desaina);
  Geometry getGeometryFromBlob(uint32_t blobId, Desaina *desaina);
}
