#include "document/src/document.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/src/node-base/type.generated.h"
#include "utility/coords.h"
#include "spdlog/spdlog.h"

namespace dea::document {

using namespace node;

Document::Document(uint32_t sessionId) : sessionId_(sessionId), change_(*this) {
	Iter::doc_ = this;
}

void Document::dump() {
	Iter iter(root_);
	while (iter.isValid()) {
		auto* node = iter.get();
		++iter;
	}
}

void Document::dump(node::Node* node) const {
  Iter iter(node);
  while (iter.isValid()) {
    auto* node = iter.get();
    spdlog::info("{}", getNodeTypeString(node));
    ++iter;
  }
}

std::vector<node::Node*> Document::getNodesWithRadius(const SkPoint& point, float radius) {
  std::vector<node::Node*> nodes;
  if (!currentPage_) {
    return nodes;
  }

  IterWithWorldMatrix iter(currentPage_);
  while (iter.isValid()) {
    auto* node = iter.get();
    if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
      auto local = utility::mapPointToLocal(point, iter.getWorldMatrix());
      auto localRect = SkRect::MakeXYWH(local.x() - radius / 2, local.y() - radius / 2, radius, radius);
      auto size = shape->getSize();
      auto bound = SkRect::MakeXYWH(0, 0, size.x, size.y);
      if (bound.intersects(localRect)) {
        nodes.push_back(node);
      }
    }
    ++iter;
  }
  return nodes;
}

}
