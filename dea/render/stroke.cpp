#include "geometry.h"
#include "include/core/SkPaint.h"
#include "resource.h"
#include "resource.h"
#include <cassert>
#include "include/core/SkPaint.h"
#include "include/core/SkPathUtils.h"

namespace dea::render {
	using namespace dea::node;
	using namespace dea::resource;

	GeometryType buildStroke(const node::DefaultShapeNode* node) {
    auto path = buildFill(node);
    float strokeWidth = node->getStrokeWeight();
    SkPaint paint{};
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(strokeWidth);
    SkPath strokePath{};
    skpathutils::FillPathWithPaint(path, paint, &strokePath);
    return strokePath;
	}

	GeometryType buildStroke(node::NodeConstPtr node) {
		auto* shapeNode = node::node_cast<const DefaultShapeNode>(node);
		if (shapeNode) {
			return buildStroke(shapeNode);
		}
		return GeometryType{};
	}

	GeometryType getOrBuildStroke(node::NodeConstPtr node) {
		auto* shapeNode = node::node_cast<const DefaultShapeNode>(node);
		if (shapeNode) {
      if (auto& pathes = shapeNode->getStrokeGeometry(); !pathes.empty()) {
        return *getOrBuild(pathes.front().commandsBlob);
      }
		}
		return GeometryType{};
	}

} // namespace dea::geometry