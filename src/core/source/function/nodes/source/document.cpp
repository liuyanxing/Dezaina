#include "desaina_kiwi.h"
#include "desaina.h"
#include "desaina_node.h"
#include "util/node_children.h"
#include "document.h"
#include "page.h"

void Document::buildDocTree() {
	for (auto& [_, node] : idNodeMap_) {
		const auto parentId = node->get_parent();
		// 0 is the document node
		if (parentId.localId == 0) {
			continue;
		}
		auto parentNodeOrNull = getValueFromMap(idNodeMap_, parentId);
		if (parentNodeOrNull.has_value()) {
			auto parentNode = parentNodeOrNull.value();
			util::appendChild(parentNode, node);
		}
	}
}

void Document::createDefaultFile() {
	set_name("new file");
	auto page = createNode<PageNode>();
	page->set_name("page 1");
	appendChild(page);
}

void Document::encode(Desaina_Kiwi::Message &message, kiwi::MemoryPool &pool) {
	message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
	auto& nodeChanges = message.set_nodeChanges(pool, 1);
	auto* nodeChange = nodeChanges.begin();
}

void Document::builPath() {}

void Document::close() {}

