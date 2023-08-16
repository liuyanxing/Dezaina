#include "base_type.h"

#include "document.h"
#include "node_type.h"

using NodeChildren = vector<Node*>;
namespace util {
	inline const NodeChildren& getChildren(const Node* parent) {
		if (util::isDocument(parent)) {
			auto document = static_cast<const Document*>(parent);
			return document->getChildren();
		}
		else if (util::isPage(parent)) {
			auto page = static_cast<const PageNode*>(parent);
			return page->getChildren();
		}
		else if (util::isFrame(parent)) {
			auto frame = static_cast<const FrameNode*>(parent);
			return frame->getChildren();
		}
		else {
			assert(false);
		}
	}

	inline void appendChild(Node* parent, Node* child) {
		const NodeChildren& children = getChildren(parent);
    const_cast<NodeChildren&>(children).push_back(child);
	}

	inline bool isContainer(Node* node) {
		return util::isDocument(node) || util::isPage(node) || util::isFrame(node);
	}

  inline Node* getRootContainer(Node* node) {
    if (util::isDocument(node)) {
      return node;
    }
    else if (util::isPage(node)) {
      return node;
    }
    else if (util::isFrame(node)) {
      return node;
    }
    else {
      assert(false);
    }
  }
} // util