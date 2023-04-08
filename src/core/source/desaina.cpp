#include "desaina_node.h"
#include "desaina.h"


bool Desaina::processMessage(uint8_t *buffer, uint32_t size) {
	Desaina_Kiwi::Message message{};
	kiwi::ByteBuffer kiwiBuffer(buffer, size);
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(kiwiBuffer, pool);
	if (!decode_success) {
		return false;
	}
	auto type = message.type();
	if (type == nullptr) {
		return false;
	}

	using Desaina_Kiwi::MessageType;
	switch (*type) {
		case MessageType::NODE_CHANGES:
			applyNodeChanges(message);
			break;
		default:
			break;
	}
	return true;
}

void Desaina::applyNodeChanges(Desaina_Kiwi::Message message) {
	auto node_changs = message.nodeChanges();
	for (auto& node_change : *node_changs) {
		if (node_change.type() == nullptr) {
			return;
		}
		applyNodeChange(node_change);	
	}
}

void Desaina::applyNodeChange(Desaina_Kiwi::NodeChange node_change) {
	GUID id;
	id.applyChange(*node_change.id());
	auto node_or_null = document.getNodeById(id);
	Node* node;
	if (!node_or_null.has_value()) {
		auto type = *node_change.type();
		using Desaina_Kiwi::NodeType;
		switch (type) {
			case NodeType::DOCUMENT:
				node = &document;
				break;
			case NodeType::CANVAS:
				node = document.createNode<PageNode>();
				break;
			case NodeType::FRAME:
				node = document.createNode<FrameNode>();
				break;
			case NodeType::RECTANGLE:
				node = document.createNode<RectangleNode>();
				break;
			default:
				break;
		}
		node->set_id(idGenerator.genId());
		document.addNodeToMap(node);
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
}
