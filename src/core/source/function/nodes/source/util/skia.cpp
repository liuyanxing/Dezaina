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

  SkPath toSkPath(const Blob* blob) {
    SkPath path;
    size_t i = 0;
    while (i < blob->size()) {
      auto type = blob->readByte();
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          path.moveTo(blob->readFloat(), blob->readFloat());
          break;
        }
        case 2: {
          path.lineTo(blob->readFloat(), blob->readFloat());
          break;
        }
        case 3: {
          path.quadTo(
            blob->readFloat(), blob->readFloat(),
            blob->readFloat(), blob->readFloat()
          );
          break;
        }
        case 4: {
          path.cubicTo(
            blob->readFloat(), blob->readFloat(),
            blob->readFloat(), blob->readFloat(),
            blob->readFloat(), blob->readFloat()
          );
          break;
        }
        default: {
          assert(false);
          break;
        }
      }
    }
    path.dump();

    return path;
  }

}
