#pragma once

#include "include/core/SkMatrix.h"
#include "document.h"
#include "node.h"
#include "node/src/node-base/type.generated.h"
#include "utility/skia.h"

namespace dea::document {

inline SkMatrix getTransfromMatrix(const node::Node* node) {
  if (auto* page = node::node_cast<const node::PageNode*>(node)) {
    return utility::toSkMatrix(page->getTransform());
  }
  if (auto* shape = node::node_cast<const node::DefaultShapeNode*>(node)) {
    return utility::toSkMatrix(shape->getTransform());
  }
  return SkMatrix::I();
}

inline SkMatrix getWorldMatrix(node::Node* node) {
	document::Document::Iter iter(node);
	SkMatrix matrix = SkMatrix::I();
	while(iter.isValid() && !node::node_cast<const node::DocumentNode*>(iter.get())) {
    matrix.preConcat(getTransfromMatrix(iter.get()));
		--iter;
	};
	return matrix;
}


}