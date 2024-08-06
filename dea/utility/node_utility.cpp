#include "node_utility.h"

namespace dea::utility{

NodeIter::NodeIter(node::Node* node, const GetParentFunc& getParent) : node_(node), root_(node_), getParent_(getParent) {
  world_ = getWorldMatrixImpl(root_);
  wordStack_.push_back(world_);
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
    node_ = container->firstChild();
		return End;
	}

	auto* next = node_->getNextSibling();
	if (next) {
    node_ = next;
		return Right;
	}
	auto* parent = getParent_(node_);
	if (!parent || parent == root_) {
		node_ = nullptr;
		return End;
	}
  node_ = parent->getNextSibling();
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

NodeIterWithWorldMatrix::NodeIterWithWorldMatrix(node::Node* node, const GetParentFunc& getParent) : NodeIter(node, getParent) {
  word_ = getWorldMatrixImpl(node);
  worldStack_.push_back(world_);
}

SkMatrix NodeIterWithWorldMarix::getWorldMatrixImpl(node::Node* node) {
  if (auto* page = node::node_cast<node::PageNode*>(node)) {
    return SkMartrix::I();
  }
  return SkMatrix::I();
}

NodeIter::IterDirection NodeIterWithWorldMarix::operator++() {
  auto direction = NodeIter::++();
  switch (direction) {
    case Forward:
      world_ = getTransfromMatrix(node_) * world_;
      wordStack_.push_back(world_);
      break;
    case Backword:
      wordStack_.pop_back();
      wordStack_.pop_back();
      word_ = getTransfromMatrix(node_) * wordStack_.top();
      wordStack_.push_back(world_);
      break;
    case Right:
      wordStack_.pop_back();
      word_ = getTransfromMatrix(node_) * wordStack_.top();
      wordStack_.push_back(world_);
      break;
    case End:
      break;
  }
}

}