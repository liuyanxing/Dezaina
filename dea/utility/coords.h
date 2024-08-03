#pragma once

#include "include/core/SkMatrix.h"

namespace dea::utility {
inline SkPoint mapPointToLocal(SkPoint point, const SkMatrix& matrix) {
  // invert matrix
  SkMatrix invertMatrix;
  if (!matrix.invert(&invertMatrix)) {
    return SkPoint::Make(0, 0);
  }
  return invertMatrix.mapPoint(point);
}
}