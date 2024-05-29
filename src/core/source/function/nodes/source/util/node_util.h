#pragma once

#include "document.h"
#include "include/core/SkMatrix.h"

class NodeUtil {
public:
  NodeUtil(Document* document) : document_(document) {}

  Node* getParent(const Node* node);

  SkMatrix getWorldMatrix(const Node* node);
  SkMatrix getTransfromMatrix(const Node* node);
  SkRect getLocalBound(const Node* node);
  SkRect getScreenBound(const Node* node);
  SkMatrix getScreenTransformMatrix(const Node* node);

  std::array<float, 4> getCornerRadius(const Node* node);

	bool isDocument(const Node* node) { return node->get_type() == NodeType::DOCUMENT; }
	bool isPage(const Node* node) { return node->get_type() == NodeType::CANVAS; }
	bool isFrame(const Node* node) { return node->get_type() == NodeType::FRAME; }
	bool isRectangle(const Node* node) { return node->get_type() == NodeType::RECTANGLE || node->get_type() == NodeType::ROUNDED_RECTANGLE; }
  bool isStar(const Node* node) { return node->get_type() == NodeType::STAR; }
  bool isEllipse(const Node* node) { return node->get_type() == NodeType::ELLIPSE; }
  bool isLine(const Node* node) { return node->get_type() == NodeType::LINE; }
  bool isPolygon(const Node* node) { return node->get_type() == NodeType::REGULAR_POLYGON; }
	bool isContainer(const Node *node) { return isDocument(node) || isPage(node) || isFrame(node); }
	bool isSceneNode(const Node* node) { return !(isDocument(node) || isPage(node)); }
  bool isVector(const Node* node) { return node->get_type() == NodeType::VECTOR; }
  bool isText(const Node* node) { return node->get_type() == NodeType::TEXT; }
  bool isInsatance(const Node* node) { return node->get_type() == NodeType::INSTANCE; }
  bool isSymbol(const Node* node) { return node->get_type() == NodeType::SYMBOL; }

  bool isDefaultShapeNode(const Node* node) {
    return isRectangle(node) ||
           isFrame(node) ||
           isText(node) ||
           isStar(node) ||
           isEllipse(node) ||
           isLine(node) ||
           isPolygon(node) ||
           isVector(node);
  }

private:
  Document* document_;
};
