#include "document.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRect.h"
#include "include/core/SkSize.h"
#include "node_type.h"
#include "util/node_props.h"
#include "util/skia.h"

namespace util {
  inline SkSize getNodeSize(Node* node) {
    if (util::isPage(node)) {
      return SkSize::MakeEmpty();
    }
    if (util::isDefaultShapeNode(node)) {
      auto shape = static_cast<DefaultShapeNode*>(node);
      return SkSize::Make(shape->get_size().x, shape->get_size().y);
    }
    return SkSize::MakeEmpty();
  }
  inline bool isPointInNode(Node* node, float x, float y) {
    auto size = getNodeSize(node);
    auto rect = SkRect::MakeIWH(size.width(), size.height());
    return rect.contains(x, y);
  }
  inline auto getWorldMatrix(Node* node, Document* document) {
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
}
