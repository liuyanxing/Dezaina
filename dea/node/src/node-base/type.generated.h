#pragma once

#include "node.h"
#include <type_traits>

namespace dea::node
{

class RectangleNode;
class LineNode;
class EllipseNode;
class PolygonNode;
class StarNode;
class VectorNode;
class FrameNode;
class SymbolNode;
class InstanceNode;
class TextNode;
class PageNode;
class DocumentNode;

template<typename T>
T node_cast(Node* node) {
	if (node->getType() == NodeType::RECTANGLE) {
		if constexpr (std::is_convertible_v<RectangleNode, T>) {
			return static_cast<T>((RectangleNode*)(node));
		}
	}
	if (node->getType() == NodeType::LINE) {
		if constexpr (std::is_convertible_v<LineNode, T>) {
			return static_cast<T>((LineNode*)(node));
		}
	}
	if (node->getType() == NodeType::ELLIPSE) {
		if constexpr (std::is_convertible_v<EllipseNode, T>) {
			return static_cast<T>((EllipseNode*)(node));
		}
	}
	if (node->getType() == NodeType::REGULAR_POLYGON) {
		if constexpr (std::is_convertible_v<PolygonNode, T>) {
			return static_cast<T>((PolygonNode*)(node));
		}
	}
	if (node->getType() == NodeType::STAR) {
		if constexpr (std::is_convertible_v<StarNode, T>) {
			return static_cast<T>((StarNode*)(node));
		}
	}
	if (node->getType() == NodeType::VECTOR) {
		if constexpr (std::is_convertible_v<VectorNode, T>) {
			return static_cast<T>((VectorNode*)(node));
		}
	}
	if (node->getType() == NodeType::FRAME) {
		if constexpr (std::is_convertible_v<FrameNode, T>) {
			return static_cast<T>((FrameNode*)(node));
		}
	}
	if (node->getType() == NodeType::SYMBOL) {
		if constexpr (std::is_convertible_v<SymbolNode, T>) {
			return static_cast<T>((SymbolNode*)(node));
		}
	}
	if (node->getType() == NodeType::INSTANCE) {
		if constexpr (std::is_convertible_v<InstanceNode, T>) {
			return static_cast<T>((InstanceNode*)(node));
		}
	}
	if (node->getType() == NodeType::TEXT) {
		if constexpr (std::is_convertible_v<TextNode, T>) {
			return static_cast<T>((TextNode*)(node));
		}
	}
	if (node->getType() == NodeType::CANVAS) {
		if constexpr (std::is_convertible_v<PageNode, T>) {
			return static_cast<T>((PageNode*)(node));
		}
	}
	if (node->getType() == NodeType::DOCUMENT) {
		if constexpr (std::is_convertible_v<DocumentNode, T>) {
			return static_cast<T>((DocumentNode*)(node));
		}
	}
	return nullptr;
}

} // namespace dea::node