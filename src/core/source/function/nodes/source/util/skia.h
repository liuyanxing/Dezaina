#include "desaina_node.h"
#include "include/core/SkMatrix.h"

namespace util {
	inline SkMatrix toSkiaMatrix(const Matrix& matrix) {
		return SkMatrix::MakeAll(
      matrix.get_m00(), matrix.get_m01(), matrix.get_m02(),
      matrix.get_m10(), matrix.get_m11(), matrix.get_m12(),
			0, 0, 1
		);
	}
}