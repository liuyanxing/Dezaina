#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "include/core/SkSize.h"
namespace base {
  inline SkPoint mapPointToLocal(SkPoint point, const SkMatrix& matrix) {
    // invert matrix
    SkMatrix invertMatrix;
    if (!matrix.invert(&invertMatrix)) {
      return SkPoint::Make(0, 0);
    }
    return invertMatrix.mapPoint(point);
  }
  inline SkSize mapSizeToLocal(SkSize size, const SkMatrix& matrix) {
    // invert matrix
    SkMatrix invertMatrix;
    if (!matrix.invert(&invertMatrix)) {
      return SkSize::Make(0, 0);
    }
    SkPoint orgin = invertMatrix.mapXY(0, 0);
    SkPoint point = invertMatrix.mapXY(size.width(), size.height());
    return SkSize::Make(point.x() - orgin.x(), point.y() - orgin.y());
  }
}
