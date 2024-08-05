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

inline SkSize getScreenSize(const node::Node* node) {
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    auto& size = shape->getSize();
    return Dezaina::instance().viewport().mapWorldToScreen({size.x, size.y});
  }
  return {0, 0};
}

inline SkMatrix getWorldMatrix(const node::Node* node) {
  document::Document::IterWithWorldMatrix iter{node};
  return iter.getWorldMatrix();
}

inline SkMatrix getWorldMatrix(const interaction::InteractionNode* node) {
  interaction::Interaction::IterWithWorldMatrix iter{node};
  return iter.getWorldMatrix();
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
  GetParentFunc getParent_;
};

class NodeIterWithWorldMatrix : public NodeIter {
public:
  NodeIter(node::Node* node, const GetParentFunc& getParent);
	IterDirection operator++();
	IterDirection operator--();
priate:
  SkMatrix world_;
  base::array<SkMatrix, 16> wordStack_;
};

}