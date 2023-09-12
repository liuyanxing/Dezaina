#include "buffer.h"
#include "services/blob_service.h"
#include "skia.h"
namespace util {
  Buffer toBuffer(const SkPath &path) {
    Buffer buffer;
    SkPath::Iter iter(path, false);
    SkPoint points[4];
    SkPath::Verb type;
    
    while ((type = iter.next(points)) != SkPath::kDone_Verb) {
      switch (type) {
        case SkPath::kMove_Verb: {
          buffer.writeByte(1);
          buffer.writeFloat(points[0].fX);
          buffer.writeFloat(points[0].fY);
          break;
        }
        case SkPath::kLine_Verb: {
          buffer.writeByte(2);
          buffer.writeFloat(points[1].fX);
          buffer.writeFloat(points[1].fY);
          break;
        }
        case SkPath::kQuad_Verb: {
          buffer.writeByte(3);
          buffer.writeFloat(points[1].fX);
          buffer.writeFloat(points[1].fY);
          buffer.writeFloat(points[2].fX);
          buffer.writeFloat(points[2].fY);
          break;
        }
        case SkPath::kCubic_Verb: {
          buffer.writeByte(4);
          buffer.writeFloat(points[1].fX);
          buffer.writeFloat(points[1].fY);
          buffer.writeFloat(points[2].fX);
          buffer.writeFloat(points[2].fY);
          buffer.writeFloat(points[3].fX);
          buffer.writeFloat(points[3].fY);
          break;
        }
        case SkPath::kClose_Verb: {
          buffer.writeByte(0);
          break;
        }
        default: {
          assert(false);
        }
      }
    }
    return buffer; 
  }

  SkPath toSkPath(const Buffer* buffer) {
    SkPath path;
    size_t i = 0;
    buffer->seek(0);
    
    while (!buffer->isEnd()) {
      auto type = buffer->readByte();
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          path.moveTo(buffer->readFloat(), buffer->readFloat());
          break;
        }
        case 2: {
          path.lineTo(buffer->readFloat(), buffer->readFloat());
          break;
        }
        case 3: {
          path.quadTo(
            buffer->readFloat(), buffer->readFloat(),
            buffer->readFloat(), buffer->readFloat()
          );
          break;
        }
        case 4: {
          path.cubicTo(
            buffer->readFloat(), buffer->readFloat(),
            buffer->readFloat(), buffer->readFloat(),
            buffer->readFloat(), buffer->readFloat()
          );
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
