#pragma once

#include "desaina_node.h"
#include "document.h"

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
		return node->get_type() == NodeType::RECTANGLE;
	}

	inline bool isContainer(const Node *node) {
		return isDocument(node) || isPage(node) || isFrame(node);
	}

	inline bool isSceneNode(const Node* node) {
		return !(isDocument(node) || isPage(node));
	}
}