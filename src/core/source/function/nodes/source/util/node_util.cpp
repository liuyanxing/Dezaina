#include "node_util.h"


Node* NodeUtil::getParent(const Node* node) {
  auto parent = document_->getNodeById(node->get_parentIndex().guid);
  return parent.value();
}

SkMatrix NodeUtil::getWorldMatrix(const Node* node) {
  auto matrix = getTransfromMatrix(node);
  auto* parent = getParent(node);
  while (parent != nullptr) {
    if (util::isPage(node)) {
      break;
    }
    matrix.preConcat(getTransfromMatrix(parent));
    parent = getParent(parent);
  }
  return matrix;
}


SkMatrix NodeUtil::getTransfromMatrix(const Node* node) {
  if (util::isPage(node)) {
    return static_cast<const PageNode*>(node)->getViewMatrix();
  }
  if (util::isDefaultShapeNode(node)) {
    auto shape = static_cast<const DefaultShapeNode*>(node);
    return util::toSkMatrix(shape->get_transform());
  }
  return SkMatrix::I();
}


SkRect NodeUtil::getLocalBound(const Node* node) {
  if (isDefaultShapeNode(node)) {
      auto shape = static_cast<const DefaultShapeNode*>(node);
      return SkRect::MakeIWH(shape->get_size().x, shape->get_size().y);
    }
  return SkRect::MakeEmpty();
}