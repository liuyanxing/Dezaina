#pragma once

#include "node.h"
#include "include/core/SkBlendMode.h"
#include "include/core/SkColor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"

namespace dea::utility {
	inline SkMatrix toSkMatrix(const node::Matrix& matrix) {
		return SkMatrix::MakeAll(
      matrix.m00, matrix.m01, matrix.m02,
      matrix.m10, matrix.m11, matrix.m12,
			0, 0, 1
		);
	}
}