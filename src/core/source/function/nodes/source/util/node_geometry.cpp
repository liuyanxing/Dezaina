#include "desaina_node.h"
#include "frame.h"
#include "include/core/SkPath.h"
#include "node_type.h"
#include "rectangle.h"
#include <optional>

static std::optional<SkPath> buildRoundRectFillPath(const Node* node) {
  constexpr float raduisRatio = 0.447715521F;
  SkPath path;
  Vector size;
  float topLeftRadius;
  float topRightRadius;
  float bottomLeftRadius;
  float bottomRightRadius;
  if (util::isRectangle(node)) {
    auto rect = static_cast<const RectangleNode*>(node);
    size = rect->get_size();
    topLeftRadius = rect->get_rectangleTopLeftCornerRadius();
    topRightRadius = rect->get_rectangleTopRightCornerRadius();
    bottomLeftRadius = rect->get_rectangleBottomLeftCornerRadius();
    bottomRightRadius = rect->get_rectangleBottomRightCornerRadius();
  } else if (util::isFrame(node)) {
    auto frame = static_cast<const FrameNode*>(node);
    size = frame->get_size();
    topLeftRadius = frame->get_rectangleTopLeftCornerRadius();
    topRightRadius = frame->get_rectangleTopRightCornerRadius();
    bottomLeftRadius = frame->get_rectangleBottomLeftCornerRadius();
    bottomRightRadius = frame->get_rectangleBottomRightCornerRadius();
  } else {
    return std::nullopt;
  }
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
}

