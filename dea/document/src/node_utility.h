#pragma once
#include "document.h"

namespace dea::document {

SkMatrix getTransfromMatrix(const Node* node) {
  if (util::isPage(node)) {
    return static_cast<const PageNode*>(node)->getTransform();
  }
  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    return util::toSkMatrix(shape->get_transform());
  }
  return SkMatrix::I();
}

SkMatrix getWorldMatrix(const Node* node) {
	document::Iter iter(node);
	SkMatrix matrix = SkMatrix::I();
	while(iter.valid()&& !node::cast<node::DocumentNode>(iter.get())) {
    matrix.preConcat(getTransfromMatrix(iter.get()));
		iter--;
	};
	return matrix;
}

}