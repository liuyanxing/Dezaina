#include "../include/document.h"
#include "document/include/document.h"
#include "document/src/document.h"
#include "document/src/node_utility.h"
#include "include/core/SkRect.h"
#include "include/private/base/SkPoint_impl.h"
#include "node/src/node-base/type.generated.h"
#include "utility/coords.h"

namespace dea::document {

using namespace node;

Document::Document(uint32_t sessionId) : sessionId_(sessionId), change_(*this) {
	Iter::doc_ = this;
}

Document::Iter::Iter(node::Node* root) : node_(root), root_(root) {
    world_ = doc_->getWorldMatrix(root);
}

bool Document::Iter::setNode(node::Node* node, IterDirection direction) {
  if (!node) {
    node_ = nullptr;
    return false;
  }
  if (direction == Forward) {
    world_ = getTransfromMatrix(node) * world_;
    wordStack_.push_back(world_);
  } else {
    world_ = wordStack_.pop_back();
    world_ = getTransfromMatrix(node) * world_;
  }
  node_ = node;
  return true;
}

Document::Iter::IterDirection Document::Iter::operator++() {
	if (!node_) {
		return End;
	}

	auto* container = node::node_cast<node::Container*>(node_);
	if (container) {
    if (setNode(container->firstChild(), Forward)) {
      return Forward;
    }
		return End;
	}

	auto* next = node_->getNextSibling();
	if (next) {
    setNode(next, Right);
		return Right;
	}
	auto* parent = doc_->getParent(node_);
	if (!parent || parent == root_) {
		node_ = nullptr;
		return End;
	}
  setNode(parent->getNextSibling(), Backword);
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
  node_ = parent;
  return Backword;
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
      auto local = utility::mapPointToLocal(point, iter.world_);
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
  while(temp && !node::node_cast<const node::DocumentNode*>(temp)) {
    matrix.preConcat(getTransfromMatrix(temp));
    temp = getParent(temp);
  };
  return matrix;
}

}
