#pragma once

#include "include/core/SkPath.h"
#include "node/include/node.h"
#include "resource/include/resource.h"
#include "resource.h"
#include <optional>
#include <utility>

namespace dea::geometry {
	using GeometryType = SkPath;

	class GeometryResourceAttachment : public resource::ResourceAttachment {
	public:
		GeometryResourceAttachment(GeometryType&& geometry) : geometry_(std::move(geometry)) {};
		const GeometryType* geometry() const { return &geometry_; };
		GeometryType* geometry() { return &geometry_; };
	private:
		GeometryType geometry_;
	};

	GeometryType* getOrBuild(resource::ResourceId id);
	GeometryType getOrBuildFill(const node::Node* node);
	GeometryType getOrBuildStroke(const node::Node* node);

	GeometryType buildFill(const node::Node* node);
	GeometryType buildStroke(const node::Node* node, std::optional<float> strokeWidth = std::nullopt);
}