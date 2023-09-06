#include "change_processor.h"
#include "desaina.h"

static Buffer decodeBlob(const Desaina_Kiwi::Blob& blob) {
  auto const data_ptr = blob.bytes();
  return Buffer::MakeWithCopy(data_ptr->data(), data_ptr->size());
}

void ChangeProcessor::remapBlobId() {
	for (auto& node : message_nodes_) {
		auto& fillGeometry = util::getFillGeometry(node);
		for (auto& geometry : fillGeometry) {
		  const_cast<Path&>(geometry).commandsBlob = blob_id_remap_[geometry.commandsBlob];
		}
	}
}

bool ChangeProcessor::processMessage(kiwi::ByteBuffer& buffer) {
	Desaina_Kiwi::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
	if (!decode_success) {
		return false;
	}
	processMessage(message);
	return true;
}

bool ChangeProcessor::processMessage(const Desaina_Kiwi::Message& message) {
  auto& document = desaina_->document;

	auto type = message.type();
	if (type == nullptr) {
		return false;
	}
	blob_id_remap_.clear();
	message_nodes_.clear();
	
	if (auto* blobPtr = message.blobs()) {
    auto& blobs = *blobPtr;
    int index = 0;
    for (auto& blob : blobs) {
    	if (!document.isLoaded()) {
    		// todo add blob without query;
    	};
      auto gblob = decodeBlob(blob);
    	auto geometry = desaina_->addGeomtryFromBlob(gblob);
    	blob_id_remap_[index++] = geometry.first;
    }
  }
  
	using Desaina_Kiwi::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			applyNodeChanges(message);
			break;
		default:
			break;
	}
	
	if (document.isLoaded()) {
		remapBlobId();
	}
	
	return true;
}

void ChangeProcessor::applyNodeChange(const Desaina_Kiwi::NodeChange &node_change) {
  auto& document = desaina_->document;
	GUID id;
	auto* guid = node_change.guid();
	id.applyChange(*guid);
	auto node_or_null = document.getNodeById(id);
	Node* node = nullptr;
	if (!node_or_null.has_value()) {
		auto type = *node_change.type();
		using Desaina_Kiwi::NodeType;
		switch (type) {
			case NodeType::DOCUMENT:
				node = &document;
				break;
			case NodeType::CANVAS:
				node = document.createNode<PageNode>(id);
				break;
			case NodeType::FRAME:
				node = document.createNode<FrameNode>(id);
				break;
			case NodeType::RECTANGLE:
      case NodeType::ROUNDED_RECTANGLE:
				node = document.createNode<RectangleNode>(id);
				break;
      case NodeType::VECTOR:
        node = document.createNode<VectorNode>(id);
      case NodeType::STAR:
				node = document.createNode<StarNode>(id);
				break;
			case NodeType::LINE:
				node = document.createNode<LineNode>(id);
				break;
			case NodeType::ELLIPSE:
				node = document.createNode<EllipseNode>(id);
				break;
			case NodeType::REGULAR_POLYGON:
				node = document.createNode<PolygonNode>(id);
				break;
      case NodeType::TEXT:
        node = document.createNode<TextNode>(id);
        break;
			default:
				assert(false);
				break;
		}
		document.addNodeToMap(node);
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
	message_nodes_.push_back(node);
}

void ChangeProcessor::applyNodeChanges(const Desaina_Kiwi::Message& message) {
	auto* node_changs = message.nodeChanges();
	for (const auto& node_change : *node_changs) {
		applyNodeChange(node_change);
	}
}
