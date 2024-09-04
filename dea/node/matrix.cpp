#include "node.generated.h"
#include <optional>

namespace dea::node {
	
		Matrix Matrix::operator*(const Matrix& other) const {
				Matrix result;
				result.m00 = m00 * other.m00 + m01 * other.m10 + m02 * 0;
				result.m01 = m00 * other.m01 + m01 * other.m11 + m02 * 0;
				result.m02 = m00 * other.m02 + m01 * other.m12 + m02 * 1;
				result.m10 = m10 * other.m00 + m11 * other.m10 + m12 * 0;
				result.m11 = m10 * other.m01 + m11 * other.m11 + m12 * 0;
				result.m12 = m10 * other.m02 + m11 * other.m12 + m12 * 1;
				
				return result;
		}

	  std::optional<Matrix> Matrix::getInverse() const {
				Matrix result;
				float det = m00 * m11 - m01 * m10;
				if (det == 0) {
						return std::nullopt;
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

		void Matrix::translate(float x, float y) {
			  m02 += x;
				m12 += y;
		}
}