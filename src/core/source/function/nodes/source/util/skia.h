#include "desaina_node.h"
#include "include/core/SkMatrix.h"

namespace util {
	inline SkMatrix toSkiaMatrix(const Matrix& matrix) {
		return SkMatrix::MakeAll(
			matrix.m00, matrix.m01, matrix.m02,
			matrix.m10, matrix.m11, matrix.m12,
			0, 0, 1
		);
	}
}