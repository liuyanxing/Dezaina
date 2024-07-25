#include "../include/document.h"
#include "document/include/document.h"
#include "node/src/node-base/type.generated.h"
#include <iostream>

namespace dea::document {

Document::Document(uint32_t sessionId) : sessionId_(sessionId), change_(*this) {
	Iter::doc_ = this;
}

void Document::Iter::operator++() {
	if (!node_) {
		return;
	}

	auto* container = node::node_cast<node::Container*>(node_);
	if (container) {
		node_ = container->firstChild();
		return;
	}

	auto* next = node_->getNextSibling();
	if (next) {
		node_ = next;
		return;
	}
	auto* parent = doc_->getNodeParent(node_);
	if (!parent) {
		node_ = nullptr;
		return;
	}
	node_ = parent->getNextSibling();
}

void Document::dump() {
	Iter iter(root_);
	while (iter.isValid()) {
		auto* node = iter.get();
		std::cout << node->getName() << std::endl;
		++iter;
	}
}

}