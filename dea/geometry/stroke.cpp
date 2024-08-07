#include "geometry.h"
#include "common/buffer.h"
#include "include/core/SkPaint.h"
#include "resource.h"
#include "common/data.h"
#include "resource.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>
#include "include/core/SkPaint.h"
#include "include/core/SkPathUtils.h"

namespace dea::geometry {
	using namespace dea::node;
	using namespace dea::resource;

	GeometryType buildStroke(const RectangleNode* node, std::optional<float> strokeWidth) {
    auto path = buildFill(node);
    float sWidth = strokeWidth.value_or(node->getStrokeWeight());
    SkPaint paint{};
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(10);
    SkPath strokePath{};
    skpathutils::FillPathWithPaint(strokePath, paint, &strokePath);
    return strokePath;
	}

	GeometryType buildStroke(const EllipseNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const PolygonNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const StarNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const VectorNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const FrameNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const SymbolNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const InstanceNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const TextNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const PageNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const DocumentNode* node) {
		return GeometryType{};
	}

	GeometryType buildStroke(const node::Node* node, std::optional<float> strokeWidth) {
		if (node->getType() == NodeType::RECTANGLE) {
			return buildStroke(node_cast<const RectangleNode*>(node), strokeWidth);
		} else if (node->getType() == NodeType::ELLIPSE) {
			return buildStroke(node_cast<const EllipseNode*>(node));
		} else if (node->getType() == NodeType::REGULAR_POLYGON) {
			return buildStroke(node_cast<const PolygonNode*>(node));
		} else if (node->getType() == NodeType::STAR) {
			return buildStroke(node_cast<const StarNode*>(node));
		} else if (node->getType() == NodeType::VECTOR) {
			return buildStroke(node_cast<const VectorNode*>(node));
		} else if (node->getType() == NodeType::FRAME) {
			return buildStroke(node_cast<const FrameNode*>(node));
		} else if (node->getType() == NodeType::SYMBOL) {
			return buildStroke(node_cast<const SymbolNode*>(node));
		} else if (node->getType() == NodeType::INSTANCE) {
			return buildStroke(node_cast<const InstanceNode*>(node));
		} else if (node->getType() == NodeType::TEXT) {
			return buildStroke(node_cast<const TextNode*>(node));
		} else if (node->getType() == NodeType::CANVAS) {
			return buildStroke(node_cast<const PageNode*>(node));
		} else if (node->getType() == NodeType::DOCUMENT) {
			return buildStroke(node_cast<const DocumentNode*>(node));
		} else {
			assert(false);
		}
	}

	GeometryType getOrBuildStroke(const node::Node* node) {
		auto* shapeNode = node::node_cast<const DefaultShapeNode*>(node);
		if (shapeNode) {
      if (auto& pathes = shapeNode->getStrokeGeometry(); !pathes.empty()) {
        return *getOrBuild(pathes.front().commandsBlob);
      }
		}
		return GeometryType{};
	}

} // namespace dea::geometry