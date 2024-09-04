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
	GeometryType getOrBuildFill(node::NodeConstPtr node);
	GeometryType getOrBuildStroke(node::NodeConstPtr node);

	GeometryType buildFill(node::NodeConstPtr node);
	GeometryType buildStroke(node::NodeConstPtr node);
}