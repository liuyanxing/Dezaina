#include "geometry.h"
#include "resource.h"
#include "resource.h"
#include <cassert>
#include "node.h"

namespace dea::render {
	using namespace dea::node;
	using namespace dea::resource;

	GeometryType buildRectangle(node::Vector size, float tl, float tr, float br, float bl) {
		constexpr float raduisRatio = 0.447715521F;
		GeometryType path{};

		const float cr = tl * raduisRatio;

		path.moveTo(0, tl);
		path.cubicTo(0, tl - cr, tl - cr, 0, tl, 0);
		path.lineTo(size.x - tr, 0);
		path.cubicTo(size.x - tr + cr, 0, size.x, tr - cr, size.x, tr);
		path.lineTo(size.x, size.y - br);
		path.cubicTo(size.x, size.y - br + cr, size.x - br + cr, size.y, size.x - br, size.y);
		path.lineTo(bl, size.y);
		path.cubicTo(bl - cr, size.y, 0, size.y - bl + cr, 0, size.y - bl);
		path.close();
		return path;
	}

	GeometryType buildFill(const RectangleNode* node) {
		return buildRectangle(
			node->getSize(),
		  node->getRectangleTopLeftCornerRadius(),
			node->getRectangleTopRightCornerRadius(),
			node->getRectangleBottomRightCornerRadius(),
			node->getRectangleBottomLeftCornerRadius()
			);
}

	GeometryType buildFill(const EllipseNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const PolygonNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const StarNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const VectorNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const FrameNode* node) {
		return buildRectangle(
			node->getSize(),
		  node->getRectangleTopLeftCornerRadius(),
			node->getRectangleTopRightCornerRadius(),
			node->getRectangleBottomRightCornerRadius(),
			node->getRectangleBottomLeftCornerRadius()
			);
	}

	GeometryType buildFill(const SymbolNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const InstanceNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const TextNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const PageNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const DocumentNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(NodeConstPtr node) {
		if (node->getType() == NodeType::RECTANGLE || node->getType() == NodeType::ROUNDED_RECTANGLE) {
			return buildFill(node_cast<const RectangleNode>(node));
		} else if (node->getType() == NodeType::ELLIPSE) {
			return buildFill(node_cast<const EllipseNode>(node));
		} else if (node->getType() == NodeType::REGULAR_POLYGON) {
			return buildFill(node_cast<const PolygonNode>(node));
		} else if (node->getType() == NodeType::STAR) {
			return buildFill(node_cast<const StarNode>(node));
		} else if (node->getType() == NodeType::VECTOR) {
			return buildFill(node_cast<const VectorNode>(node));
		} else if (node->getType() == NodeType::FRAME) {
			return buildFill(node_cast<const FrameNode>(node));
		} else if (node->getType() == NodeType::SYMBOL) {
			return buildFill(node_cast<const SymbolNode>(node));
		} else if (node->getType() == NodeType::INSTANCE) {
			return buildFill(node_cast<const InstanceNode>(node));
		} else if (node->getType() == NodeType::TEXT) {
			return buildFill(node_cast<const TextNode>(node));
		} else if (node->getType() == NodeType::CANVAS) {
			return buildFill(node_cast<const PageNode>(node));
		} else if (node->getType() == NodeType::DOCUMENT) {
			return buildFill(node_cast<const DocumentNode>(node));
		} else {
			assert(false);
		}
		return GeometryType{};
	}

	GeometryType getOrBuildFill(NodeConstPtr node) {
		auto* shapeNode = node::node_cast<const DefaultShapeNode>(node);
		if (shapeNode) {
      if (auto& pathes = shapeNode->getFillGeometry(); !pathes.empty()) {
        return *getOrBuild(pathes.front().commandsBlob);
      }
		}
		return GeometryType{};
	}

} // namespace dea::geometry