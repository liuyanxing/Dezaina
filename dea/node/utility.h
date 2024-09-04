#pragma once

#include "node.h"
#include "base/array.h"

namespace dea::node {

node::Matrix getTransfromMatrix(node::Node* node);
node::Size getSize(node::NodeConstPtr node);

class NodeIter {
public:
  enum IterDirection {
    Forward,
    Backword,
    Right,
    End,
  };

  using GetParentFunc = std::function<node::Node*(node::Node*)>;

	NodeIter(node::Node* node, const GetParentFunc&);
	IterDirection operator++();
	IterDirection operator--();
	bool isValid() { return node_ != nullptr; }
	auto* get() { return node_; }
  node::Node* getParent() { if (node_) return getParent_(node_); return nullptr; }
protected:
	node::Node* node_;
	node::Node* root_;
  GetParentFunc getParent_;
};

class NodeIterWithWorldMatrix : public NodeIter {
public:
  NodeIterWithWorldMatrix(node::Node* node, const GetParentFunc& getParent);
	IterDirection operator++();
	IterDirection operator--();
  const auto& getWorldMatrix() { return world_; }
protected:
  node::Matrix getWorldMatrixImpl(node::Node* node);
  node::Matrix world_;
  base::array<node::Matrix, 16> worldStack_;
};

}