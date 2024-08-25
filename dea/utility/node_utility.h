#pragma once

#include "node.h"
#include <include/core/SkMatrix.h>
#include "common/array.h"
#include "skia.h"

namespace dea::utility {

namespace interaction {
class InteractionNode;
}

SkMatrix getTransfromMatrix(node::Node* node);
SkSize getScreenSize(node::Node* node);
SkMatrix getWorldMatrix(node::Node* node);
SkMatrix getWorldMatrix(interaction::InteractionNode* node);

class NodeIter {
friend class Document;
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
  SkMatrix getWorldMatrixImpl(node::Node* node);
  SkMatrix world_;
  base::array<SkMatrix, 16> worldStack_;
};

}