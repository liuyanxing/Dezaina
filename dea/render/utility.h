#pragma once

#include "core/SkColor.h"
#include "core/SkMatrix.h"
#include "node.h"

namespace dea::render {

inline SkMatrix toSkMatrix(const node::Matrix& matrix) {
	return SkMatrix::MakeAll(
		matrix.m00, matrix.m01, matrix.m02,
		matrix.m10, matrix.m11, matrix.m12,
		0, 0, 1
	);
}
inline node::Matrix toMatrix(const SkMatrix& matrix) {
	return node::Matrix{
		matrix.get(0),
		matrix.get(1),
		matrix.get(2),
		matrix.get(3),
		matrix.get(4),
		matrix.get(5),
	};
}

inline SkColor toSkColor(const node::Color& color) {
	SkColor4f skColorf{
		color.r,
		color.g,
		color.b,
		color.a,
	};
	return skColorf.toSkColor();
}

} // namespace dea::render
