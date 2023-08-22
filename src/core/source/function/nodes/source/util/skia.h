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

namespace util {
  inline SkColor toSkColor(const Color& color) {
    return SkColorSetARGB(
      color.get_a(),
      color.get_r(),
      color.get_g(),
      color.get_b()
    );
  }

	inline SkMatrix toSkMatrix(const Matrix& matrix) {
		return SkMatrix::MakeAll(
      matrix.get_m00(), matrix.get_m01(), matrix.get_m02(),
      matrix.get_m10(), matrix.get_m11(), matrix.get_m12(),
			0, 0, 1
		);
	}

  inline SkPath toSkPath(const DataSharedPtr& blob) {
    SkPath path;
    const auto* data = static_cast<const uint8_t*>(blob->data());
    auto size = blob->size();
    size_t i = 0;
    while (i < size) {
      auto type = buffer::readByte(data, i);
      i++;
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          path.moveTo(buffer::readFloat(data, i), buffer::readFloat(data, i + 4));
          i += 8;
          break;
        }
        case 2: {
          path.lineTo(buffer::readFloat(data, i), buffer::readFloat(data, i + 4));
          i += 8;
          break;
        }
        case 3: {
          path.quadTo(
            buffer::readFloat(data, i), buffer::readFloat(data, i + 4),
            buffer::readFloat(data, i + 8), buffer::readFloat(data, i + 12)
          );
          i += 16;
          break;
        }
        case 4: {
          path.cubicTo(
            buffer::readFloat(data, i), buffer::readFloat(data, i + 4),
            buffer::readFloat(data, i + 8), buffer::readFloat(data, i + 12),
            buffer::readFloat(data, i + 16), buffer::readFloat(data, i + 20)
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

  inline SkPaint toSkPaint(const Paint& paint) {
    SkPaint skPaint;
    skPaint.setAlphaf(paint.get_opacity());
    skPaint.setBlendMode(static_cast<SkBlendMode>(paint.get_blendMode()));
    auto type = paint.get_type();
    switch (type) {
      case PaintType::SOLID: {
        const auto& truePaint = static_cast<const SolidPaint&>(paint);
        skPaint.setColor(toSkColor(truePaint.get_color()));
        break;
      }
      case PaintType::GRADIENT_LINEAR: {
        break;
      }
      case PaintType::GRADIENT_RADIAL: {
        break;
      }
      case PaintType::GRADIENT_ANGULAR: {
        break;
      }
      case PaintType::GRADIENT_DIAMOND: {
        break;
      }
      case PaintType::IMAGE: {
        break;
      }
    }
    return skPaint;
  }
}