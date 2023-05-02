#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "desaina_node.h"
#include "desaina.h"


bool Desaina::processMessage(uint8_t *buffer, uint32_t size) {
	kiwi::ByteBuffer kiwiBuffer(buffer, size);
	return processMessage(kiwiBuffer);
}


bool Desaina::processMessage(kiwi::ByteBuffer& buffer) {
	Desaina_Kiwi::Message message{};
	kiwi::MemoryPool pool;
	bool decode_success = message.decode(buffer, pool);
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

void Desaina::applyNodeChanges(const Desaina_Kiwi::Message& message) {
	auto* node_changs = message.nodeChanges();
	for (const auto& node_change : *node_changs) {
		applyNodeChange(node_change);
	}
}

void Desaina::applyNodeChange(const Desaina_Kiwi::NodeChange& node_change) {
	GUID id;
	auto* guid = node_change.id();
	id.applyChange(*guid);
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
				node = document.createNode<PageNode>(id);
				break;
			case NodeType::FRAME:
				node = document.createNode<FrameNode>(id);
				break;
			case NodeType::RECTANGLE:
				node = document.createNode<RectangleNode>(id);
				break;
			default:
				break;
		}
		document.addNodeToMap(node);
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
}
