#include "desaina.h"
#include "desaina_node.h"
#include "frame.h"
#include "include/core/SkPath.h"
#include "node_type.h"
#include "rectangle.h"
#include "util/skia.h"
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

static std::optional<SkPath> buildRoundRectFillPath(const Node* node) {
  constexpr float raduisRatio = 0.447715521F;
  SkPath path;
  SizeAndRadius sizeAndRadius;
  if (util::isRectangle(node)) {
    sizeAndRadius = getSizeAndRadius(static_cast<const RectangleNode*>(node));
  } else if (util::isFrame(node)) {
    sizeAndRadius = getSizeAndRadius(static_cast<const FrameNodeBase*>(node));
  } else {
    return std::nullopt;
  }
  
  auto [size, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius] = sizeAndRadius;
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

namespace util {
  SkPath buildFillPath(const Node *node) {
    if (auto path = buildRoundRectFillPath(node); path.has_value()) {
      return path.value();
    }
    return SkPath();
  }

  Geometry* buildFillGeometry(const Node *node, Desaina *desaina) {
    return desaina->addGeomtryFromBlob(util::toBuffer(buildFillPath(node))).second;
  }
}

