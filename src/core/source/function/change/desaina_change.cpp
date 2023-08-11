#include "desaina_kiwi.h"
#include "desaina_change.h"
#include "desaina_node.h"
#include "kiwi.h"
#include <vector>

namespace desaina_change {
	void setNodeType(Desaina_Kiwi::NodeChange* nodeChange, NodeType type) {
		if (type == NodeType::DOCUMENT) {
			nodeChange->set_type(Desaina_Kiwi::NodeType::DOCUMENT);
		}
		else if (type == NodeType::CANVAS) {
			nodeChange->set_type(Desaina_Kiwi::NodeType::CANVAS);
		}
		else if (type == NodeType::RECTANGLE) {
			nodeChange->set_type(Desaina_Kiwi::NodeType::RECTANGLE);
		}
		else if (type == NodeType::FRAME) {
			nodeChange->set_type(Desaina_Kiwi::NodeType::FRAME);
		}
	};

	void createNodeChangeMessage(NodeType type, kiwi::ByteBuffer& buffer, Desaina* desaina) {
		kiwi::MemoryPool pool;
		Desaina_Kiwi::Message message;
		message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
		auto& nodeChanges = message.set_nodeChanges(pool, 1);
		auto* nodeChange = nodeChanges.begin();
		setNodeType(nodeChange, type);
		auto* guid = pool.allocate<Desaina_Kiwi::GUID>();
		auto id = desaina->services.idGenerator->genId();
		guid->set_localID(id.get_localID());
		guid->set_sessionID(id.get_sessionID());
		nodeChange->set_guid(guid);
		message.encode(buffer);
	}
}