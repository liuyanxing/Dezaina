#include "change.h"
#include "common/data.h"
#include "../include/document.h"
#include "resource/include/resource.h"

namespace dea::document
{

bool Change::applyMessage(kiwi::ByteBuffer& buffer) {
	message::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
	if (!decode_success) {
		return false;
	}
	processMessage(message);
	return true;
}

bool Change::processBlobMessage(kiwi::Array<message::Blob>& blobs) {
	uint32_t index = 0;
	for (const auto& blob : blobs) {
		auto* bytes = blob.bytes();
		auto& data = base::Data::MakeWithCopy(bytes->data(), bytes->size());
		auto* resourceItem = resource::BlobResource::add(data);
		if (resourceItem) {
			blobIdMap_[index++] = resourceItem->id();
		}
	}
	return true;
}

bool Change::processMessage(message::Message& message) {
	auto type = message.type();
	if (type == nullptr) {
		return false;
	}
  
	using message::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			processNodeChanges(message);
			break;
		default:
			break;
	}

	blobIdMap_.clear();
	
	return true;
}

bool Change::processNodeChanges(message::Message& message) {
	using namespace dea::node;
	auto* node_changs = message.nodeChanges();
	for (auto& node_change : *node_changs) {
		GUID id;
		auto* guid = node_change.guid();
		id.applyChange(*guid);
		auto* node = doc_.getNodeById(id);
		if (!node) {
			auto type = *node_change.type();
			using message::NodeType;
			switch (type) {
				case NodeType::DOCUMENT:
					node = doc_.createNode<DocumentNode>();
					break;
				case NodeType::CANVAS:
					node = doc_.createNode<PageNode>(id);
					break;
				case NodeType::FRAME:
					node = doc_.createNode<FrameNode>(id);
					break;
				case NodeType::RECTANGLE:
				case NodeType::ROUNDED_RECTANGLE:
					node = doc_.createNode<RectangleNode>(id);
					break;
				case NodeType::VECTOR:
					node = doc_.createNode<VectorNode>(id);
					break;
				case NodeType::STAR:
					node = doc_.createNode<StarNode>(id);
					break;
				case NodeType::LINE:
					node = doc_.createNode<LineNode>(id);
					break;
				case NodeType::ELLIPSE:
					node = doc_.createNode<EllipseNode>(id);
					break;
				case NodeType::REGULAR_POLYGON:
					node = doc_.createNode<PolygonNode>(id);
					break;
				case NodeType::TEXT:
					node = doc_.createNode<TextNode>(id);
					break;
				case NodeType::SYMBOL:
					node = doc_.createNode<SymbolNode>(id);
					break;
				case NodeType::INSTANCE:
					node = doc_.createNode<InstanceNode>(id);
					break;
				default:
					assert(false);
					break;
			}
			doc_.append(node);
		} 

		for (auto& fillGeometry : *node_change.fillGeometry()) {
			fillGeometry.set_commandsBlob(blobIdMap_[*fillGeometry.commandsBlob()]);
		}

		node->applyChange(node_change);
	}
	return true;
}

} // namespace dea::change 
