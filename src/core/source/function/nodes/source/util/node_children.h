#include "document.h"

using NodeChildren = std::vector<Node*>;
namespace util {
	inline NodeChildren& getChildren(Node* parent) {
		if (parent->isDocument()) {
			auto document = static_cast<Document*>(parent);
			return document->get_children();
		}
		else if (parent->isPage()) {
			auto page = static_cast<PageNode*>(parent);
			return page->get_children();
		}
		else if (parent->isFrame()) {
			auto frame = static_cast<FrameNodeBase*>(parent);
			return frame->get_children();
		}
		else {
			assert(false);
		}
	}

	inline void appendChild(Node* parent, Node* child) {
		NodeChildren& children = getChildren(parent);
		children.push_back(child);
	}

	inline bool isContainer(Node* node) {
		return node->isDocument() || node->isPage() || node->isFrame();
	}
} // util