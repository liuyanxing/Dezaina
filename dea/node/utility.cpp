#include "utility.h"
#include "container.h"
#include "node.generated.h"
#include "node/node.h"
#include "type.generated.h"

namespace dea::node {

node::Matrix getTransfromMatrix(node::NodeConstPtr node) {
  if (auto *page = node::node_cast<node::PageNode>(node)) {
    return node::Matrix();
  }
  if (auto *shape = node::node_cast<node::DefaultShapeNode>(node)) {
    return shape->getTransform();
  }
  return node::Matrix();
}

node::Vector getSize(node::NodeConstPtr node) {
  if (auto *shape = node::node_cast<const node::DefaultShapeNode>(node)) {
    return shape->getSize();
  }
  return node::Vector();
}

node::Vector getNodeCenter(node::NodeConstPtr node) {
  return GetWorldMatrix(node) * (getSize(node) / 2);
}

NodeIter::NodeIter(node::Node *node)
    : node_(node), root_(node_) {}

bool NodeIter::tryGoChild() {
  auto *container = node::node_cast<node::Container>(node_);
  if (isSkipChild_ || !container || !container->firstChild()) {
    return false;
  }
  node_ = container->firstChild();
  return true;
}

bool NodeIter::tryGoNextSibling() {
  auto *next = node_->getNextSibling();
  if (!next) {
    return false;
  }
  node_ = next;
  return true;
}

bool NodeIter::tryGoParent() {
  auto *parent = node_->getParent();
  if (!parent) {
    return false;
  }
  node_ = parent;
  return true;
}

bool NodeIter::tryGoParentNextSibling() {
  auto *parent = node_->getParent();
  if (!parent || parent == root_) {
    node_ = nullptr;
    return false;
  }
  node_ = parent->getNextSibling();
  return node_ != nullptr;
}

NodeIter::Direction NodeIter::goNext() {
  if (tryGoChild()) return Forward; 
  if (tryGoNextSibling()) return Right;
  if (tryGoParentNextSibling()) return Backword;

  return End;
}

NodeIter::Direction NodeIter::operator++() {
  if (!node_) return End;
  return goNext();
}

NodeIter::Direction NodeIter::operator--() {
  if (!node_) return End;
  return tryGoParent() ? Backword : End;
}

NodeIterWithWorldMatrix::NodeIterWithWorldMatrix(node::Node *node)
    : NodeIter(node) {
  if (!node_) {
    return;
  }
  world_ = GetWorldMatrix(node);
  worldStack_.push_back(world_);
}

NodeIter::Direction NodeIterWithWorldMatrix::operator++() {
  auto direction = goNext();
  switch (direction) {
  case Forward:
    world_ = world_ * getTransfromMatrix(node_);
    worldStack_.push_back(world_);
    break;
  case Backword:
    worldStack_.pop_back(); // pop the current node matrix
    worldStack_.pop_back(); // pop the parent node matrix
    world_ = worldStack_.top() * getTransfromMatrix(node_);
    worldStack_.push_back(world_);
    break;
  case Right:
    worldStack_.pop_back();
    world_ = worldStack_.top() * getTransfromMatrix(node_);
    worldStack_.push_back(world_);
    break;
  case End:
    break;
  }
  return direction;
}

void NodeIterWithWorldMatrix::rest() {
  NodeIter::rest();
  update();
}

void NodeIterWithWorldMatrix::update() {
  world_ = GetWorldMatrix(node_);
  worldStack_.clear();
  worldStack_.push_back(world_);
}

} // namespace dea::node
