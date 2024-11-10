#include "geometry.h"
#include "base/buffer.h"
#include "base/data.h"
#include "geometry/geometry.h"
#include "resource.h"
#include <cassert>
#include <cstdint>
#include <memory>
#include <utility>

namespace dea::render {
using namespace dea::node;
using namespace dea::resource;
using namespace dea::geometry;

static GeometryType buildGeometry(const base::Data &data) {
  GeometryType path{};
  base::Buffer buffer(data.data<uint8_t *>(), data.size());
  buffer.seek(0);

  while (!buffer.isEnd()) {
    auto type = buffer.readByte();
    switch (type) {
    case CLOSE: {
      path.close();
      break;
    }
    case MOVE: {
      float points[2]{buffer.readFloat(), buffer.readFloat()};
      path.moveTo(points[0], points[1]);
      break;
    }
    case LINE: {
      float points[2]{buffer.readFloat(), buffer.readFloat()};
      path.lineTo(points[0], points[1]);
      break;
    }
    case QUAD: {
      float points[4]{buffer.readFloat(), buffer.readFloat(),
                      buffer.readFloat(), buffer.readFloat()};
      path.quadTo(points[0], points[1], points[2], points[3]);
      break;
    }
    case CUBIC: {
      float points[6]{buffer.readFloat(), buffer.readFloat(),
                      buffer.readFloat(), buffer.readFloat(),
                      buffer.readFloat(), buffer.readFloat()};

      path.cubicTo(points[0], points[1], points[2], points[3], points[4],
                   points[5]);
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

GeometryType *getOrBuild(ResourceId id) {
  auto *blobItem = Resource::Get<BlobResourceItem *>(id);
  if (!blobItem) {
    assert(false);
  }
  auto *attachment = blobItem->attachment<GeometryResourceAttachment *>();
  if (attachment) {
    return attachment->geometry();
  }

  auto geometry = buildGeometry(blobItem->data());
  blobItem->setAttachment(
      std::make_unique<GeometryResourceAttachment>(std::move(geometry)));
  return blobItem->attachment<GeometryResourceAttachment *>()->geometry();
}

} // namespace dea::render
