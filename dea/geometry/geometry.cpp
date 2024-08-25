#include "geometry.h"
#include "common/buffer.h"
#include "resource.h"
#include "common/data.h"
#include "resource.h"
#include <cassert>
#include <cstdint>
#include <memory>
#include <utility>

namespace dea::geometry {
	using namespace dea::node;
	using namespace dea::resource;

	static GeometryType buildGeometry(const base::Data& data) {
		GeometryType path{};
    base::Buffer buffer(data.data<uint8_t*>(), data.size());
    buffer.seek(0);
    
    while (!buffer.isEnd()) {
      auto type = buffer.readByte();
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          float points[2]{
            buffer.readFloat(), buffer.readFloat()
          };
          path.moveTo(points[1], points[0]);
          break;
        }
        case 2: {
          float points[2]{
            buffer.readFloat(), buffer.readFloat()
          };
          path.lineTo(points[1], points[0]);
          break;
        }
        case 3: {
          float points[4]{
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat()
          };
          path.quadTo(
            points[1], points[0],
            points[3], points[2]
          );
          break;
        }
        case 4: {
          float points[6]{
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat()
          };

          path.cubicTo(
            points[1], points[0],
            points[3], points[2],
            points[5], points[4]
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

	GeometryType* getOrBuild(ResourceId id) {
	  auto* blobItem = Resource::Get<BlobResourceItem*>(id);
    if (!blobItem) {
      assert(false);
    }
		auto* attachment = blobItem->attachment<GeometryResourceAttachment*>();
		if (attachment) {
			return attachment->geometry();
		}

	  auto geometry = buildGeometry(*blobItem->data());
		blobItem->setAttachment(std::make_unique<GeometryResourceAttachment>(std::move(geometry)));
		return blobItem->attachment<GeometryResourceAttachment*>()->geometry();
	}

	
} // namespace dea::geometry