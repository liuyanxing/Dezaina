#pragma once

#include "include/core/SkMatrix.h"
#include "include/core/SkPoint.h"
#include "include/core/SkScalar.h"
#include "include/core/SkSize.h"
#include <algorithm>
#include <cmath>

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
    auto angle = SkRadiansToDegrees(acosf(acosValue));
    return a.cross(b) < 0 ? -angle : angle;
  }

  inline SkVector mapVector(const SkVector& vector, const SkMatrix& matrix) {
    auto rotation =  SkRadiansToDegrees(acosf(float(matrix.getScaleX())));
    int sign = asinf(float(matrix.getSkewY())) > 0 ? 1 : -1;
    rotation *= -sign;
    SkMatrix m;
    m.setRotate(rotation);
    return m.mapVector(vector.x(), vector.y());
  }
  
  inline float getRotation(const SkMatrix& matrix) {
    return SkRadiansToDegrees(atan2f(matrix.getSkewY(), matrix.getScaleX()));
  }

  inline SkVector getTranslateOfBound(const SkRect& bound, const SkMatrix& matrix) {
    auto center = SkPoint::Make(bound.width() / 2, bound.height() / 2);
    SkPoint point = matrix.mapPoint(center);
    return point - center;
  }
}
