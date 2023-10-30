#include "change_system/layouts/layout_node.h"
#include "desaina.h"
#include "desaina_node.h"
#include "frame.h"
#include "include/core/SkPath.h"
#include "node_type.h"
#include "rectangle.h"
#include "services/blob_service.h"
#include "util/skia.h"
#include "vector.h"
#include "node_vector.h"
#include <_types/_uint32_t.h>
#include <optional>
#include <tuple>

using SizeAndRadius = std::tuple<Vector, float, float, float, float>;
template<typename T>
static SizeAndRadius getSizeAndRadius(const T* node) {
    Vector size = node->get_size();
    float topLeftRadius = node->get_rectangleTopLeftCornerRadius();
    float topRightRadius = node->get_rectangleTopRightCornerRadius();
    float bottomLeftRadius = node->get_rectangleBottomLeftCornerRadius();
    float bottomRightRadius = node->get_rectangleBottomRightCornerRadius();
    return {size, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius};
}

static std::optional<SkPath> buildRoundRectFillPath(const LayoutNode* node) {
  constexpr float raduisRatio = 0.447715521F;
  SkPath path;
  auto size = node->size;
  auto topLeftRadius = node->topLeftRadius;
  auto topRightRadius = node->topRightRadius;
  auto bottomLeftRadius = node->bottomLeftRadius;
  auto bottomRightRadius = node->bottomRightRadius;
  const float bezierRadius = topLeftRadius * raduisRatio;
  
  path.moveTo(0, topLeftRadius);
  path.cubicTo(0, topLeftRadius - bezierRadius, topLeftRadius - bezierRadius, 0, topLeftRadius, 0);
  path.lineTo(size.x - topRightRadius, 0);
  path.cubicTo(size.x - topRightRadius + bezierRadius, 0, size.x, topRightRadius - bezierRadius, size.x, topRightRadius);
  path.lineTo(size.x, size.y - bottomRightRadius);
  path.cubicTo(size.x, size.y - bottomRightRadius + bezierRadius, size.x - bottomRightRadius + bezierRadius, size.y, size.x - bottomRightRadius, size.y);
  path.lineTo(bottomLeftRadius, size.y);
  path.cubicTo(bottomLeftRadius - bezierRadius, size.y, 0, size.y - bottomLeftRadius + bezierRadius, 0, size.y - bottomLeftRadius);
  path.close();
  return path;
}

static SkPath buildVectorGeometry(const LayoutNode *layoutNode, Desaina *desaina) {
  auto vectorDecodedData = node::decodeVectorData(layoutNode->vectorData); 
  layoutNode->vectorData->setAttachment<node::VectorDecodedData>(vectorDecodedData);
  auto* cycles = vectorDecodedData.cycles;
  SkPath path;
  for (auto& cycle : *cycles) {
    path.addPath(cycle.path);
  }
  return path;
}

using DesainaPath = Path;

namespace util {
  SkPath buildFillPath(const LayoutNode *layoutNode) {
    const auto* node = layoutNode->node;
    if (auto path = buildRoundRectFillPath(layoutNode); path.has_value()) {
      return path.value();
    }
    return SkPath();
  }

  BlobPair buildFillGeometry(const LayoutNode *node, Desaina *desaina) {
    if (util::isVector(node->node)) {
      return desaina->addBlob(util::toBuffer(buildVectorGeometry(node, desaina)));
    }
    return desaina->addBlob(util::toBuffer(buildFillPath(node)));
  }

  const IVector<DesainaPath>& getFillGeometry(const Node* node) {
    static IVector<DesainaPath> empty;
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return shape->get_fillGeometry();
    }
    return empty;
  }

  const IVector<DesainaPath>& getStrokeGeometry(const Node* node) {
    static IVector<DesainaPath> empty;
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return shape->get_strokeGeometry();
    }
    return empty;
  }

  const VectorData& getVectorData(const Node* node) {
    auto vectorNode = static_cast<const VectorNode*>(node);
    return vectorNode->get_vectorData();
  }

  Geometry getGeometryFromBlob(uint32_t blobId, Desaina *desaina) {
    auto* blob = desaina->getBlob(blobId);
    auto* geometry = blob->getAttachment<Geometry>();
    if (geometry != nullptr) {
      return *geometry;
    }
    return *(blob->setAttachment<Geometry>(blob));
  }
}

