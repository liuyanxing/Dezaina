#pragma once

#include "core/SkColor.h"
#include "core/SkMatrix.h"
#include "node.h"

namespace dea::render {
inline SkColor toSkColor(const node::Color &color) {
  return SkColorSetARGB(color.a, color.r, color.g, color.b);
}

inline SkMatrix toSkMatrix(const node::Matrix &matrix) {
	SkMatrix skMatrix;
	skMatrix.setAll(matrix.m00, matrix.m01, matrix.m02, matrix.m10, matrix.m11, matrix.m12, 0, 0, 1);
	return skMatrix;
}

} // namespace dea::render
