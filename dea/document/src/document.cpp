#include "../include/document.h"
#include "document/include/document.h"
#include "document/src/document.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/src/node-base/node.generated.h"
#include "node/src/node-base/type.generated.h"
#include "utility/coords.h"
#include "dezaina.h"

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

std::vector<node::Node*> Document::getNodesWithRadius(const SkPoint& point, float radius) {
  std::vector<node::Node*> nodes;
  if (!currentPage_) {
    return nodes;
  }

  Iter iter(currentPage_);
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

SkMatrix Document::getWorldMatrix(node::Node* node) {
  SkMatrix matrix = SkMatrix::I();
  auto temp = node;
  while(temp && !node::node_cast<const node::PageNode*>(temp)) {
    matrix.preConcat(utility::getTransfromMatrix(temp));
    temp = getParent(temp);
  };
  return matrix;
}

SkBound Document::getLocalBound(node::Node* node) {
  if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
    return SkBound::MakeWH(shape->getSize().getX(), shape->getSize().getY());
  }
  return SkBound::MakeEmpty();
}

SkBound Document::getWorldBound(node::Node* node) {
  auto matrix = getWorldMatrix(node);
  return matrix.mapRect(getLocalBound(node));
}

SkBound Document::getScreenBound(node::Node* node) {
  auto bound = getWorldBound(node);
  auto& viewport = Dezaina::instance().getViewport();
  return viewport.mapWorldToScreen(getLocalBound(node));
}

SkMatrix Document::getScreenMatrix(node::Node* node) {
  auto matrix = getWorldMatrix(node);
  auto& viewport = Dezaina::instance().getViewport();
  matrix.preConcat(viewport.VPMatrix());
  return matrix;
}

}
