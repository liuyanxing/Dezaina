#include "../include/document.h"
#include "document/include/document.h"
#include "document/src/document.h"
#include "document/src/node_utility.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/src/node-base/type.generated.h"
#include "utility/coords.h"
#include <iostream>

namespace dea::document {

Document::Document(uint32_t sessionId) : sessionId_(sessionId), change_(*this) {
	Iter::doc_ = this;
}

void Document::Iter::setNode(node::Node* node, IterDirection direction) {
  if (direction == Forward) {
    world_ = getTransfromMatrix(node) * world_;
    wordStack_[++stackTop_] = world_;
  } else {
    world_ = wordStack_[--stackTop_];
    world_ = getTransfromMatrix(node) * world_;
  }
  node_ = node;
}

Document::Iter::IterDirection Document::Iter::operator++() {
	if (!node_) {
		return End;
	}

	auto* container = node::node_cast<node::Container*>(node_);
	if (container) {
		node_ = container->firstChild();
		return Forward;
	}

	auto* next = node_->getNextSibling();
	if (next) {
		node_ = next;
		return Right;
	}
	auto* parent = doc_->getParent(node_);
	if (!parent || parent == root_) {
		node_ = nullptr;
		return End;
	}
	node_ = parent->getNextSibling();
  return Backword;
}

Document::Iter::IterDirection Document::Iter::operator--() {
	if (!node_) {
		return End;
	}

	auto* parent = doc_->getParent(node_);
	if (!parent) {
		node_ = nullptr;
		return End;
	}
  return Backword;
}

void Document::dump() {
	Iter iter(root_);
	while (iter.isValid()) {
		auto* node = iter.get();
		std::cout << node->getName() << std::endl;
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
      auto local = utility::mapPointToLocal(point, iter.world_);
      auto localRect = SkRect::MakeXYWH(-radius / 2, -radius / 2, radius, radius);
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