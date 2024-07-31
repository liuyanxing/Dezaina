#include "geometry.h"
#include "common/buffer.h"
#include "resource.h"
#include "common/data.h"
#include "node/src/node-base/node.generated.h"
#include "node/src/node-base/type.generated.h"
#include "node/src/rectangle.h"
#include "resource.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>

namespace dea::geometry {
	using namespace dea::node;
	using namespace dea::resource;

	GeometryType buildFill(const RectangleNode* node) {
		constexpr float raduisRatio = 0.447715521F;
		GeometryType path{};

    float tl = node->getRectangleTopLeftCornerRadius();
    float tr = node->getRectangleTopRightCornerRadius(); 
    float br = node->getRectangleBottomRightCornerRadius();
    float bl = node->getRectangleBottomLeftCornerRadius();

		auto size = node->getSize();
		// beizer control point radius
		const float cr = tl * raduisRatio;
  
		path.moveTo(0, tl);
		path.cubicTo(0, tl - cr, tl - cr, 0, tl, 0);
		path.lineTo(size.x - tr, 0);
		path.cubicTo(size.x - tr + cr, 0, size.x, tr - cr, size.x, tr);
		path.lineTo(size.x, size.y - br);
		path.cubicTo(size.x, size.y - br + cr, size.x - br + cr, size.y, size.x - br, size.y);
		path.lineTo(bl, size.y);
		path.cubicTo(bl - cr, size.y, 0, size.y - bl + cr, 0, size.y - bl);
		path.close();
		return path;
	}

	GeometryType buildFill(const EllipseNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const PolygonNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const StarNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const VectorNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const FrameNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const SymbolNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const InstanceNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const TextNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const PageNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const DocumentNode* node) {
		return GeometryType{};
	}

	GeometryType buildFill(const Node* node) {
		if (node->getType() == NodeType::RECTANGLE) {
			return buildFill(node_cast<const RectangleNode*>(node));
		} else if (node->getType() == NodeType::ELLIPSE) {
			return buildFill(node_cast<const EllipseNode*>(node));
		} else if (node->getType() == NodeType::REGULAR_POLYGON) {
			return buildFill(node_cast<const PolygonNode*>(node));
		} else if (node->getType() == NodeType::STAR) {
			return buildFill(node_cast<const StarNode*>(node));
		} else if (node->getType() == NodeType::VECTOR) {
			return buildFill(node_cast<const VectorNode*>(node));
		} else if (node->getType() == NodeType::FRAME) {
			return buildFill(node_cast<const FrameNode*>(node));
		} else if (node->getType() == NodeType::SYMBOL) {
			return buildFill(node_cast<const SymbolNode*>(node));
		} else if (node->getType() == NodeType::INSTANCE) {
			return buildFill(node_cast<const InstanceNode*>(node));
		} else if (node->getType() == NodeType::TEXT) {
			return buildFill(node_cast<const TextNode*>(node));
		} else if (node->getType() == NodeType::CANVAS) {
			return buildFill(node_cast<const PageNode*>(node));
		} else if (node->getType() == NodeType::DOCUMENT) {
			return buildFill(node_cast<const DocumentNode*>(node));
		} else {
			assert(false);
		}
	}

	static GeometryType* getGeometry(ResourceId id) {
	  auto* BlobItem = Resource::Get<BlobResourceItem*>(id);
		auto* attachment = BlobItem->attachment<GeometryResourceAttachment*>();
		if (attachment) {
			return attachment->geometry();
		}
		return nullptr;
	}

	static GeometryType* getFill(const DefaultShapeNode* node) {
		auto fillId = node->getFillGeometry().front().commandsBlob;
		return getGeometry(fillId);
	}

	static GeometryType* getStroke(const DefaultShapeNode* node) {
		auto strokeId = node->getStrokeGeometry().front().commandsBlob;
		return getGeometry(strokeId);
	}

	// static base::Data serialize(const GeometryType& geometry) {
	// 	return base::Data{};
	// }

	// static ResourceItem* store(GeometryType&& geometry) {
	// }

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

	static GeometryType* getOrBuild(ResourceId id) {
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

	GeometryType* getOrBuildFill(const node::Node* node) {
		auto* shapeNode = node::node_cast<const DefaultShapeNode*>(node);
		if (shapeNode) {
			return getOrBuild(shapeNode->getFillGeometry().front().commandsBlob);
		}
		return nullptr;
	}

	GeometryType* getOrBuildStroke(const node::Node* node) {
		// auto* shapeNode = node::node_cast<const DefaultShapeNode*>(node);
		// if (shapeNode) {
		// 	return getOrBuild(shapeNode->getStrokeGeometry().front().commandsBlob);
		// }
		return nullptr;
	}
	
} // namespace dea::geometry