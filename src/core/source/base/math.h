#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "include/core/SkSize.h"
#include <algorithm>

inline SkPoint operator*(const SkPoint& point, const SkPoint& other) {
  return SkPoint::Make(point.x() * other.x(), point.y() * other.y());
}
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
  inline float vectorsAngle(const SkPoint& a, const SkPoint& b) {
    auto acosValue = std::clamp(a.dot(b) / (a.length() * b.length()), -1.0f, 1.0f);
    auto angle = acosf(acosValue) * 180 / M_PI;
    return a.cross(b) < 0 ? -angle : angle;
  }
}
