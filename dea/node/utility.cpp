#include "utility.h"
#include "node/node.h"
#include "type.generated.h"
#include "node.generated.h"
#include "container.h"

namespace dea::node{

node::Matrix getTransfromMatrix(node::Node* node) {
  if (auto* page = node::node_cast<const node::PageNode*>(node)) {
    return node::Matrix();
  }
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    return shape->getTransform();
  }
  return node::Matrix();
}

node::Size getSize(node::NodeConstPtr node) {
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    auto& size = shape->getSize();
    return {size.x, size.y};
  }
  return node::Size();
}

NodeIter::NodeIter(node::Node* node, const GetParentFunc& getParent) : node_(node), root_(node_), getParent_(getParent) {}

NodeIter::IterDirection NodeIter::operator++() {
	if (!node_) {
		return End;
	}

	auto* container = node::node_cast<node::Container*>(node_);
	if (container) {
    node_ = container->firstChild();
		return node_ ? Forward : End;
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
  return node_ ? Backword : End;
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
  if (!node_) {
    return;
  }
  world_ = getWorldMatrixImpl(node);
  worldStack_.push_back(world_);
}

node::Matrix NodeIterWithWorldMatrix::getWorldMatrixImpl(node::Node* node) {
  if (auto* page = node::node_cast<node::PageNode*>(node)) {
    return node::Matrix();
  }
  node::Matrix world = getTransfromMatrix(node);
  auto* parent = getParent_(node);
  while (parent && !node::node_cast<node::PageNode*>(parent)) {
    world = getTransfromMatrix(parent) * world;
    parent = getParent_(parent);
  }
  return world;
}

NodeIter::IterDirection NodeIterWithWorldMatrix::operator++() {
  auto direction = NodeIter::operator++();
  switch (direction) {
    case Forward:
      world_ = getTransfromMatrix(node_) * world_;
      worldStack_.push_back(world_);
      break;
    case Backword:
      worldStack_.pop_back();
      worldStack_.pop_back();
      world_ = getTransfromMatrix(node_) * worldStack_.top();
      worldStack_.push_back(world_);
      break;
    case Right:
      worldStack_.pop_back();
      world_ = getTransfromMatrix(node_) * worldStack_.top();
      worldStack_.push_back(world_);
      break;
    case End:
      break;
  }
  return direction;
}

}