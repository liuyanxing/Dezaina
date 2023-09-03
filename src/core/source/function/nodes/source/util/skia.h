#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkBlendMode.h"
#include "include/core/SkColor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"

#include "base/buffer.h"
#include <cassert>
#include <variant>

namespace util {
  inline SkColor toSkColor(const Color& color) {
    SkColor4f skColorf{
      color.r,
      color.g,
      color.b,
      color.a,
    };
    return skColorf.toSkColor();
  }

	inline SkMatrix toSkMatrix(const Matrix& matrix) {
		return SkMatrix::MakeAll(
      matrix.m00, matrix.m01, matrix.m02,
      matrix.m10, matrix.m11, matrix.m12,
			0, 0, 1
		);
	}

  inline SkRect rotate(const SkRect& rect, float angle, float x = 0, float y = 0) {
    SkMatrix matrix;
    matrix.setRotate(angle, x, y);
    return matrix.mapRect(rect);
  }

  inline Matrix toMatrix(const SkMatrix& matrix) {
    return Matrix{
      matrix.get(0), matrix.get(1), matrix.get(2),
      matrix.get(3), matrix.get(4), matrix.get(5),
    };
  }

  inline SkPath toSkPath(const DataSharedPtr& blob) {
    SkPath path;
    const auto* data = static_cast<const uint8_t*>(blob->data());
    auto size = blob->size();
    size_t i = 0;
    while (i < size) {
      auto type = Buffer::readByte(data, i);
      i++;
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          path.moveTo(Buffer::readFloat(data, i), Buffer::readFloat(data, i + 4));
          i += 8;
          break;
        }
        case 2: {
          path.lineTo(Buffer::readFloat(data, i), Buffer::readFloat(data, i + 4));
          i += 8;
          break;
        }
        case 3: {
          path.quadTo(
            Buffer::readFloat(data, i), Buffer::readFloat(data, i + 4),
            Buffer::readFloat(data, i + 8), Buffer::readFloat(data, i + 12)
          );
          i += 16;
          break;
        }
        case 4: {
          path.cubicTo(
            Buffer::readFloat(data, i), Buffer::readFloat(data, i + 4),
            Buffer::readFloat(data, i + 8), Buffer::readFloat(data, i + 12),
            Buffer::readFloat(data, i + 16), Buffer::readFloat(data, i + 20)
          );
          i += 24;
          break;
        }
        default: {
          assert(false);
          break;
        }
      }
    }

    return path;
  }

  inline SkPaint toSkPaint(const PaintUnion& paint) {
    SkPaint skPaint;
    skPaint.setAntiAlias(true);
    if (auto value = std::get_if<SolidPaint>(&paint)) {
      skPaint.setAlphaf(value->opacity);
      skPaint.setBlendMode(static_cast<SkBlendMode>(value->blendMode));
      skPaint.setColor(toSkColor(value->get_color()));
    }
    return skPaint;
  }
}
