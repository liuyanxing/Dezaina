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

NodeIter::IterDirection NodeIter::operator++() {
  if (!node_) {
    return End;
  }

  auto *container = node::node_cast<node::Container>(node_);
  if (container && !isSkipChild_) {
    node_ = container->firstChild();
    return node_ ? Forward : End;
  }

  auto *next = node_->getNextSibling();
  if (next) {
    node_ = next;
    return Right;
  }
  auto *parent = node_->getParent();
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

  auto *parent = node_->getParent();
  if (!parent) {
    node_ = nullptr;
    return End;
  }
  node_ = parent;
  return Backword;
}

NodeIterWithWorldMatrix::NodeIterWithWorldMatrix(node::Node *node)
    : NodeIter(node) {
  if (!node_) {
    return;
  }
  world_ = GetWorldMatrix(node);
  worldStack_.push_back(world_);
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
