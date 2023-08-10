#include "base_type.h"

#include "document.h"

using NodeChildren = vector<Node*>;
namespace util {
	inline NodeChildren& getChildren(Node* parent) {
		if (parent->isDocument()) {
			auto document = static_cast<Document*>(parent);
			return document->getChildren();
		}
		else if (parent->isPage()) {
			auto page = static_cast<PageNode*>(parent);
			return page->getChildren();
		}
		else if (parent->isFrame()) {
			auto frame = static_cast<FrameNode*>(parent);
			return frame->getChildren();
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

  inline Node* getRootContainer(Node* node) {
    if (node->isDocument()) {
      return node;
    }
    else if (node->isPage()) {
      return node;
    }
    else if (node->isFrame()) {
      return node;
    }
    else {
      assert(false);
    }
  }
} // util