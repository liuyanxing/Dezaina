#pragma once

#include "gfx_types.h"

namespace dea::gfx {

class Network {
public:
	static Network buildFromData(const base::Data& data, SkArenaAlloc& arena);

	auto* getVertecies() {
		return &vertecies_;
	}
	auto* getSegments() {
		return &segments_;
	}
	bool empty() {
		return vertecies_.empty() && segments_.empty();
	}

	void buildSKPath();
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
