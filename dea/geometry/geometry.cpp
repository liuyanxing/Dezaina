#include "geometry.h"
#include "common/buffer.h"
#include "resource.h"
#include "common/data.h"
#include "resource.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>

namespace dea::geometry {
	using namespace dea::node;
	using namespace dea::resource;

	static GeometryType buildGeometry(const base::Data& data) {
		GeometryType path{};
    base::Buffer buffer(data.data<uint8_t*>(), data.size());
    size_t i = 0;
    buffer.seek(0);
    
    while (!buffer.isEnd()) {
      auto type = buffer.readByte();
      switch (type) {
        case 0: {
          path.close();
          break;
        }
        case 1: {
          path.moveTo(buffer.readFloat(), buffer.readFloat());
          break;
        }
        case 2: {
          path.lineTo(buffer.readFloat(), buffer.readFloat());
          break;
        }
        case 3: {
          path.quadTo(
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat()
          );
          break;
        }
        case 4: {
          path.cubicTo(
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat(),
            buffer.readFloat(), buffer.readFloat()
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