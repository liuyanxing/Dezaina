#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
namespace base {
  inline SkPoint mapPointToLocal(float x, float y, const SkMatrix& matrix) {
    // invert matrix
    SkMatrix invertMatrix;
    if (!matrix.invert(&invertMatrix)) {
      return SkPoint::Make(0, 0);
    }
    return invertMatrix.mapXY(x, y);
  }
}
