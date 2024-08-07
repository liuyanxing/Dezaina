#include "node_utility.h"
#include "document.h"
#include "interaction.h"
#include "dezaina.h"
#include "node/src/node-base/node.h"

namespace dea::utility{

SkMatrix getTransfromMatrix(node::Node* node) {
  if (auto* page = node::node_cast<const node::PageNode*>(node)) {
    return utility::toSkMatrix(page->getTransform());
  }
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    return utility::toSkMatrix(shape->getTransform());
  }
  return SkMatrix::I();
}

SkSize getScreenSize(node::Node* node) {
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    auto& size = shape->getSize();
    return Dezaina::instance().getViewport().mapWorldToScreen(SkSize{size.x, size.y});
  }
  return {0, 0};
}

SkMatrix getWorldMatrix(node::Node* node) {
  document::Document::IterWithWorldMatrix iter{node};
  return iter.getWorldMatrix();
}

SkMatrix getWorldMatrix(interaction::InteractionNode* node) {
  dea::interaction::Interaction::IterWithWorldMatrix iter{static_cast<node::Node*>((void*)node)};
  return iter.getWorldMatrix();
}

NodeIter::NodeIter(node::Node* node, const GetParentFunc& getParent) : node_(node), root_(node_), getParent_(getParent) {}

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
  world_ = getWorldMatrixImpl(node);
  worldStack_.push_back(world_);
}

SkMatrix NodeIterWithWorldMatrix::getWorldMatrixImpl(node::Node* node) {
  if (auto* page = node::node_cast<node::PageNode*>(node)) {
    return SkMatrix::I();
  }
  return SkMatrix::I();
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