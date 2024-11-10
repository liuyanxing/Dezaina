#pragma once

#include "gfx_types.h"
#include "include/src/base/SkArenaAlloc.h"
#include "include/src/pathops/SkOpContour.h"
#include "base/data.h"
#include "include/core/SkPath.h"

namespace dea::gfx {

class Network {
public:
	static void buildFromData(const base::Data& data, SkArenaAlloc& arena, Network& network);

	auto* getVertecies() {
		return &vertecies_;
	}
	auto* getSegments() {
		return &segments_;
	}
	bool empty() {
		return vertecies_.empty() && segments_.empty();
	}

	void buildSkPath();
	void buildCycles(SkArenaAlloc& arena);

	private:
		VertexPtrArray vertecies_;
		SegmentPtrArray segments_;
		ContourCycles cycles_;
		SegmentPtrArray buildPlanarSegemts(SkArenaAlloc& allocator);
		SkPath skPath_;

		SkOpContourHead* computeIntersections();
};

} // namespace gfx
