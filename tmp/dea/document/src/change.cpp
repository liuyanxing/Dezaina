#include "change.h"
#include "common/data.h"
#include "node/include/node.h"
#include "resource/include/resource.h"

namespace dea::change
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

bool Change::processBlobChanges(const kiwi::Array<message::Blob>& blobs) {
	for (const auto& blob : blobs) {
		auto* bytes = blob.bytes();
		auto& data = base::Data::MakeWithCopy(bytes->data(), bytes->size());
		auto* resourceItem = resource::BlobResource::add(data);
		if (resourceItem) {
		}
	}
	return true;
}

bool Change::processMessage(const message::Message& message) {
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
	
	return true;
}

bool Change::processNodeChanges(const message::Message& message) {
	using namespace dea::node;
	auto* node_changs = message.nodeChanges();
	for (const auto& node_change : *node_changs) {
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

		node->applyChange(node_change);
		return node;
	}
}

} // namespace dea::change 
