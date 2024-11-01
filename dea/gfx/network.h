#pragma once

#include "gfx_types.h"

namespace gfx {

class Network {
public:
	Network() = default;

	Network(const base::Data& data, ArenaAlloc& arena);
	Network(Network&& that) {
		*this = std::move(that);
	}
	Network& operator=(Network&& that) {
		vertecies_ = std::move(that.vertecies_);
		segments_ = std::move(that.segments_);
		return *this;
	}
	auto* getVertecies() {
		return &vertecies_;
	}
	auto* getSegments() {
		return &segments_;
	}
	bool empty() {
		return vertecies_.empty() && segments_.empty();
	}
	private:
		VertexArray vertecies_;
		SegmentArray segments_;
		ContourCycles cycles_;
};

} // namespace gfx
