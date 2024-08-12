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
T node_cast(NodeConstPtr node) {
	using U = std::remove_cv_t<std::remove_pointer_t<T>>;
	if (node->getType() == NodeType::RECTANGLE || node->getType() == NodeType::ROUNDED_RECTANGLE) {
		if constexpr (std::is_convertible_v<RectangleNode, U>) {
			return static_cast<T>((RectangleNode*)(node));
		}
	}
	if (node->getType() == NodeType::LINE) {
		if constexpr (std::is_convertible_v<LineNode, U>) {
			return static_cast<T>((LineNode*)(node));
		}
	}
	if (node->getType() == NodeType::ELLIPSE) {
		if constexpr (std::is_convertible_v<EllipseNode, U>) {
			return static_cast<T>((EllipseNode*)(node));
		}
	}
	if (node->getType() == NodeType::REGULAR_POLYGON) {
		if constexpr (std::is_convertible_v<PolygonNode, U>) {
			return static_cast<T>((PolygonNode*)(node));
		}
	}
	if (node->getType() == NodeType::STAR) {
		if constexpr (std::is_convertible_v<StarNode, U>) {
			return static_cast<T>((StarNode*)(node));
		}
	}
	if (node->getType() == NodeType::VECTOR) {
		if constexpr (std::is_convertible_v<VectorNode, U>) {
			return static_cast<T>((VectorNode*)(node));
		}
	}
	if (node->getType() == NodeType::FRAME) {
		if constexpr (std::is_convertible_v<FrameNode, U>) {
			return static_cast<T>((FrameNode*)(node));
		}
	}
	if (node->getType() == NodeType::SYMBOL) {
		if constexpr (std::is_convertible_v<SymbolNode, U>) {
			return static_cast<T>((SymbolNode*)(node));
		}
	}
	if (node->getType() == NodeType::INSTANCE) {
		if constexpr (std::is_convertible_v<InstanceNode, U>) {
			return static_cast<T>((InstanceNode*)(node));
		}
	}
	if (node->getType() == NodeType::TEXT) {
		if constexpr (std::is_convertible_v<TextNode, U>) {
			return static_cast<T>((TextNode*)(node));
		}
	}
	if (node->getType() == NodeType::CANVAS) {
		if constexpr (std::is_convertible_v<PageNode, U>) {
			return static_cast<T>((PageNode*)(node));
		}
	}
	if (node->getType() == NodeType::DOCUMENT) {
		if constexpr (std::is_convertible_v<DocumentNode, U>) {
			return static_cast<T>((DocumentNode*)(node));
		}
	}
	return nullptr;
}

} // namespace dea::node