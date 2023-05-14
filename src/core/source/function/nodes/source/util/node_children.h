#include "node_type.h"

using NodeChildren = std::vector<Node*>;
namespace util {
	inline const NodeChildren& getChildren(const Node* parent) {
		if (isDocument(parent)) {
			auto document = static_cast<const Document*>(parent);
			return document->get_children();
		}
		else if (isPage(parent)) {
			auto page = static_cast<const PageNode*>(parent);
			return page->get_children();
		}
		else if (isFrame(parent)) {
			auto frame = static_cast<const FrameNodeBase*>(parent);
			return frame->get_children();
		}
		else {
			assert(false);
		}
	}

	inline void appendChild(Node* parent, Node* child) {
		if (isDocument(parent)) {
			auto document = static_cast<Document*>(parent);
			document->appendChild(child);
		}
		else if (isPage(parent)) {
			auto page = static_cast<PageNode*>(parent);
			page->appendChild(child);
		}
		else if (isFrame(parent)) {
			auto frame = static_cast<FrameNodeBase*>(parent);
			frame->appendChild(child);
		}
		else {
			assert(false);
		}
	}

} // util