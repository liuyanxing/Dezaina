#include "node_utility.h"

namespace dea::utility{

NodeIter::NodeIter(node::Node* node, const GetParentFunc& getParent) : node_(node), root_(node_), getParent_(getParent) {
  world_ = getWorldMatrixImpl(root_);
  wordStack_.push_back(world_);
}

SkMatrix NodeIter::getWorldMatrixImpl(node::Node* node) {
  if (auto* page = node::node_cast<node::PageNode*>(node)) {
    return utility::toSkMatrix(page->getTransform());
  }
  if (auto* shape = node::node_cast<node::DefaultShapeNode*>(node)) {
    return utility::toSkMatrix(shape->getTransform());
  }
  return SkMatrix::I();
}

bool NodeIter::setNode(node::Node* node, IterDirection direction) {
  if (!node) {
    node_ = nullptr;
    return false;
  }
  if (direction == Forward) {
    world_ = getTransfromMatrix(node) * world_;
    wordStack_.push_back(world_);
  } else if(direction == Right) {
    world_ = wordStack_.pop_back();
    world_ = getTransfromMatrix(node) * world_;
    wordStack_.push_back(world_);
  } else if (direction == Backword) {
    world_ = wordStack_.pop_back();
    world_ = getTransfromMatrix(node) * world_;
  }
  node_ = node;
  return true;
}

NodeIter::IterDirection NodeIter::operator++() {
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
	auto* parent = getParent_(node_);
	if (!parent || parent == root_) {
		node_ = nullptr;
		return End;
	}
  setNode(parent->getNextSibling(), Backword);
  return Backword;
}

NodeIter::IterDirection NodeIter::operator--() {
	if (!node_) {
		return End;
	}

	auto* parent = getParent_(node_);
	if (!parent) {
		node_ = nullptr;
		return End;
	}
  node_ = parent;
  return Backword;
}
}