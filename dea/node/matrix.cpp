#include "node.generated.h"
#include <cmath>

namespace dea::node {

Matrix Matrix::operator*(const Matrix &other) const {
  Matrix result;
  result.m00 = m00 * other.m00 + m01 * other.m10 + m02 * 0;
  result.m01 = m00 * other.m01 + m01 * other.m11 + m02 * 0;
  result.m02 = m00 * other.m02 + m01 * other.m12 + m02 * 1;
  result.m10 = m10 * other.m00 + m11 * other.m10 + m12 * 0;
  result.m11 = m10 * other.m01 + m11 * other.m11 + m12 * 0;
  result.m12 = m10 * other.m02 + m11 * other.m12 + m12 * 1;

  return result;
}

bool Matrix::operator==(const Matrix &other) const {
  return m00 == other.m00 && m01 == other.m01 && m02 == other.m02 &&
         m10 == other.m10 && m11 == other.m11 && m12 == other.m12;
}

Matrix Matrix::getInverse(const Matrix &defaultValue) const {
  Matrix result;
  float det = m00 * m11 - m01 * m10;
  if (det == 0) {
    return defaultValue;
  }
  float invDet = 1.0f / det;
  result.m00 = m11 * invDet;
  result.m01 = -m01 * invDet;
  result.m02 = (m01 * m12 - m11 * m02) * invDet;
  result.m10 = -m10 * invDet;
  result.m11 = m00 * invDet;
  result.m12 = (m10 * m02 - m00 * m12) * invDet;
  return result;
}

Matrix &Matrix::preRotate(float angle, Vector center) {
  return *this = *this * Translate(center) * Rotate(angle) *
                 Translate(-center);
}

float Matrix::getRotation() const { return -std::atan2(m01, m00); }

Vector Matrix::operator*(const Vector &rhs) const {
  return Vector(m00 * rhs.x + m01 * rhs.y + m02,
                m10 * rhs.x + m11 * rhs.y + m12);
}

Vector Matrix::mapPoint(const Vector &point) const { return *this * point; }

Vector Matrix::mapVector(const Vector &vector) const {
  return operator*(vector);
}

void Matrix::preTranslate(float x, float y) {
  *this = *this * Translate(x, y);
}

void Matrix::preScale(float x, float y) {
  *this = *this * Scale(x, y);
}

void Matrix::preScale(float x, float y, float cx, float cy) {
  *this = *this * Translate(cx, cy) * Scale(x, y) * Translate(-cx, -cy);
}

} // namespace dea::node
