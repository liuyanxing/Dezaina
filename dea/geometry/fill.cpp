#include "base/buffer.h"
#include "geometry.h"
#include "node/type.generated.h"
#include "resource.h"
#include <corecrt_math_defines.h>

namespace dea::geometry {
using namespace dea::node;
using namespace dea::resource;
using namespace dea::base;

Data buildRectangle(node::Vector size, float tl, float tr, float br, float bl) {
  constexpr float raduisRatio = 0.447715521F;
  const float cr = tl * raduisRatio;

  Buffer buffer;
  buffer.write(MOVE, 0, tl, CUBIC, 0, tl - cr, tl - cr, 0, tl, 0, LINE,
               size.x - tr, 0, CUBIC, size.x - tr + cr, 0, size.x, tr - cr,
               size.x, tr, LINE, size.x, size.y - br, CUBIC, size.x,
               size.y - br + cr, size.x - br + cr, size.y, size.x - br, size.y,
               LINE, bl, size.y, CUBIC, bl - cr, size.y, 0, size.y - bl + cr, 0,
               size.y - bl, CLOSE);
  return buffer.toData();
}

Data buildPolygon(node::Vector size, int sides, float radius) {
  Buffer buffer;
  buffer.write(MOVE, size.x / 2, 0);
  const float angle = 2 * M_PI / sides;
  for (int i = 0; i < sides; ++i) {
    buffer.write(LINE, size.x / 2 + size.x / 2 * cos(angle * i),
                 size.y / 2 + size.y / 2 * sin(angle * i));
  }
  buffer.write(CLOSE);
  return buffer.toData();
}

Data buildStar(node::Vector size, int count, float ratio, float radius) {
  Buffer buffer;
  buffer.write(MOVE, size.x / 2, 0);
  const float angle = 2 * M_PI / count;
  for (int i = 0; i < count; ++i) {
    buffer.write(LINE, size.x / 2 + size.x / 2 * cos(angle * i),
                 size.y / 2 + size.y / 2 * sin(angle * i),
                  LINE, size.x / 2 + size.x / 2 * ratio * cos(angle * i + angle / 2),
                 size.y / 2 + size.y / 2 * ratio * sin(angle * i + angle / 2));
  }
  buffer.write(CLOSE);
  return buffer.toData();
}

Data buildEllipse(node::Vector size) {
  Buffer buffer;
  buffer.write(MOVE, size.x / 2, 0);
  buffer.write(CUBIC, size.x, 0, size.x, size.y, size.x / 2, size.y);
  buffer.write(CUBIC, 0, size.y, 0, 0, size.x / 2, 0);
  buffer.write(CLOSE);
  return buffer.toData();
}

Data buildLine(node::Vector size) {
  Buffer buffer;
  buffer.write(MOVE, 0, 0);
  buffer.write(LINE, size.x, 0);
  buffer.write(LINE, size.x, size.y);
  buffer.write(LINE, 0, size.y);
  buffer.write(CLOSE);
  return buffer.toData();
}

Data buildFill(const RectangleNode *node) {
  return buildRectangle(node->getSize(),
                        node->getRectangleTopLeftCornerRadius(),
                        node->getRectangleTopRightCornerRadius(),
                        node->getRectangleBottomRightCornerRadius(),
                        node->getRectangleBottomLeftCornerRadius());
}

Data buildFill(const EllipseNode *node) { return buildEllipse(node->getSize()); }

Data buildFill(const PolygonNode *node) {
  return buildPolygon(node->getSize(), node->getCount(),
                      node->getCornerRadius());
}

Data buildFill(const StarNode *node) {
  return Data{};
  // return buildStar(node->getSize(), node->getCount(), node->getCornerRadius(),
  //                  node->getCornerRadius());
}

Data buildFill(const VectorNode *node) { return Data{}; }

Data buildFill(const FrameNode *node) {
  return buildRectangle(node->getSize(),
                        node->getRectangleTopLeftCornerRadius(),
                        node->getRectangleTopRightCornerRadius(),
                        node->getRectangleBottomRightCornerRadius(),
                        node->getRectangleBottomLeftCornerRadius());
}

Data buildFill(const SymbolNode *node) { return Data{}; }

Data buildFill(const InstanceNode *node) { return Data{}; }

Data buildFill(const TextNode *node) { return Data{}; }

Data buildFill(const PageNode *node) { return Data{}; }

Data buildFill(const DocumentNode *node) { return Data{}; }

Data buildFill(NodeConstPtr node) {
  if (auto *rectangle = node_cast<const RectangleNode>(node)) {
    return buildFill(rectangle);
  } else if (node->getType() == NodeType::ELLIPSE) {
    return buildFill(node_cast<const EllipseNode>(node));
  } else if (node->getType() == NodeType::REGULAR_POLYGON) {
    return buildFill(node_cast<const PolygonNode>(node));
  } else if (node->getType() == NodeType::STAR) {
    return buildFill(node_cast<const StarNode>(node));
  } else if (node->getType() == NodeType::VECTOR) {
    return buildFill(node_cast<const VectorNode>(node));
  } else if (node->getType() == NodeType::FRAME) {
    return buildFill(node_cast<const FrameNode>(node));
  } else if (node->getType() == NodeType::SYMBOL) {
    return buildFill(node_cast<const SymbolNode>(node));
  } else if (node->getType() == NodeType::INSTANCE) {
    return buildFill(node_cast<const InstanceNode>(node));
  } else if (node->getType() == NodeType::TEXT) {
    return buildFill(node_cast<const TextNode>(node));
  } else if (node->getType() == NodeType::CANVAS) {
    return buildFill(node_cast<const PageNode>(node));
  } else if (node->getType() == NodeType::DOCUMENT) {
    return buildFill(node_cast<const DocumentNode>(node));
  } else {
    assert(false);
  }
  return Data{nullptr, 0};
}

} // namespace dea::geometry
