#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPath.h"

#include "base/buffer.h"
#include <cassert>

namespace util {
	inline SkMatrix toSkiaMatrix(const Matrix& matrix) {
		return SkMatrix::MakeAll(
      matrix.get_m00(), matrix.get_m01(), matrix.get_m02(),
      matrix.get_m10(), matrix.get_m11(), matrix.get_m12(),
			0, 0, 1
		);
	}

  inline SkPath toSkiaPath(const DataSharedPtr& blob) {
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
}