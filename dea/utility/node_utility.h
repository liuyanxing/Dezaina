#pragma once

#include "node.h"
#include <include/core/SkMatrix.h>
#include "common/array.h"
#include "skia.h"

namespace dea::utility {

inline SkMatrix getTransfromMatrix(const node::Node* node) {
  if (auto* page = node::node_cast<const node::PageNode*>(node)) {
    return utility::toSkMatrix(page->getTransform());
  }
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    return utility::toSkMatrix(shape->getTransform());
  }
  return SkMatrix::I();
}

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
  auto& getWorldMatrix() { return world_; }
private:
	node::Node* node_;
	node::Node* root_;
  SkMatrix world_;
  base::array<SkMatrix, 16> wordStack_;
  GetParentFunc getParent_;
  bool setNode(node::Node* node, IterDirection direction);
  SkMatrix getWorldMatrixImpl(node::Node* node);
};

}