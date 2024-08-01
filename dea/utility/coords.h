#pragma once

namespace dea::utility {
  inline SkPoint mapPointToLocal(const SkMatrix& matrix, SkPoint point) {
    // invert matrix
    SkMatrix invertMatrix;
    if (!matrix.invert(&invertMatrix)) {
      return SkPoint::Make(0, 0);
    }
    return invertMatrix.mapPoint(point);
  }
}