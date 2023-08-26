#include "base_type.h"
#include "desaina_node.h"
#include "node_type.h"
#include "page.h"
#include "skia.h"

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
}