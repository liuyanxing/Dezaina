#pragma once

#include "desaina_node.h"

using Node = BaseNodeMixin;

namespace util {
	inline bool isDocument(const Node* node) {
		return node->get_type() == NodeType::DOCUMENT;
	}

	inline bool isPage(const Node* node) {
		return node->get_type() == NodeType::CANVAS;
	}

	inline bool isFrame(const Node* node) {
		return node->get_type() == NodeType::FRAME;
	}

	inline bool isRectangle(const Node* node) {
		return node->get_type() == NodeType::RECTANGLE || node->get_type() == NodeType::ROUNDED_RECTANGLE;
	}

  inline bool isStar(const Node* node) {
    return node->get_type() == NodeType::STAR;
  }

  inline bool isEllipse(const Node* node) {
    return node->get_type() == NodeType::ELLIPSE;
  }

  inline bool isLine(const Node* node) {
    return node->get_type() == NodeType::LINE;
  }

  inline bool isPolygon(const Node* node) {
    return node->get_type() == NodeType::REGULAR_POLYGON;
  }

	inline bool isContainer(const Node *node) {
		return isDocument(node) || isPage(node) || isFrame(node);
	}

	inline bool isSceneNode(const Node* node) {
		return !(isDocument(node) || isPage(node));
	}

  inline bool isVector(const Node* node) {
    return node->get_type() == NodeType::VECTOR;
  }

  inline bool isText(const Node* node) {
    return node->get_type() == NodeType::TEXT;
  }

  inline bool isDefaultShapeNode(const Node* node) {
    return isRectangle(node) ||
           isFrame(node) ||
           isText(node) ||
           isStar(node) ||
           isEllipse(node) ||
           isLine(node) ||
           isPolygon(node) ||
           isVector(node);
  }
}