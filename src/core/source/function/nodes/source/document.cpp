#include "desaina_kiwi.h"
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

void Document::close() {
}

