#include "desaina_kiwi.h"
#include "desaina_node.h"
#include "document.h"
#include "page.h"

bool Document::load(const uint8_t* buffer, uint32_t size) {
	if (isLoaded) {
		close();
	}
	Desaina_Kiwi::Message message{};

	kiwi::ByteBuffer kiwiBuffer(buffer, size);

	kiwi::MemoryPool pool;
  bool decode_success = message.decode(kiwiBuffer, pool);
	if (!decode_success) {
		return false;
	}

	applyNodeChanges(message);
	isLoaded = true;
	return isLoaded;
}

void Document::applyNodeChanges(Desaina_Kiwi::Message message) {
	auto node_changs = message.nodeChanges();
	for (auto& node_change : *node_changs) {
		if (node_change.type() == nullptr) {
			return;
		}
		switch (*node_change.type()) {
		case Desaina_Kiwi::NodeType::CANVAS: {
			node_change.id();
			break;
		}
		case Desaina_Kiwi::NodeChange::Type::Update: {
			auto update_node_change = static_cast<Desaina_Kiwi::UpdateNodeChange*>(node_change);
			auto node = getNodeById(update_node_change->id());
			node->attributes = update_node_change->attributes();
			break;
		}
		case Desaina_Kiwi::NodeChange::Type::Delete: {
			auto delete_node_change = static_cast<Desaina_Kiwi::DeleteNodeChange*>(node_change);
			auto node = getNodeById(delete_node_change->id());
			node->parent = 0;
			break;
		}
		default:
			break;
		}
	}
}

void Document::applyNodeChange(Desaina_Kiwi::NodeChange node_change) {
	GUID id;
	id.applyChange(*node_change.id());
	auto node_or_null = getNodeById(id);
	Node* node;
	if (!node_or_null.has_value()) {
		auto type = *node_change.type();
		using Desaina_Kiwi::NodeType;
		switch (type) {
			case NodeType::CANVAS:
				node = createNode<PageNode>();
				break;
			case NodeType::FRAME:
				node = createNode<FrameNode>();
				break;
			case NodeType::RECTANGLE:
				node = createNode<RectangleNode>();
				break;
			default:
				break;
		}
	} else {
		node = node_or_null.value();
	}

	node->applyChange(node_change);
}

void Document::close() {
}
