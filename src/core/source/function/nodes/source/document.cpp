#include "node_type.h"
#include "document.h"
#include "page.h"
#include "util/node_container.h"
#include <iostream>

void Document::buildDocTree() {
	for (auto& [_, node] : idNodeMap_) {
		if (util::isDocument(node)) {
			continue;
		}

		const auto parentId = node->get_parentIndex().guid;
		auto parentNodeOrNull = getNodeById(parentId);
		if (parentNodeOrNull.has_value()) {
			auto parentNode = parentNodeOrNull.value();
			util::appendChild(parentNode, node);
		}

    if (util::isInsatance(node)) {
      auto instanceNode = static_cast<InstanceNode*>(node);
    }
	}
}

void Document::createDefaultFile() {
  set_name("new file");
	auto page = createNode<PageNode>();
	page->set_name("page 1");
	appendChild(page);
}

void Document::iterateNode(Node *node, std::function<bool (Node *)> func) {
	if (!func(node)) {
		return;
	}
	if (util::isContainer(node)) {
		iterateChildren(node, func);
	}
}

void Document::iterateChildren(Node *node, std::function<bool (Node *)> func) {
	if (!util::isContainer(node)) {
		return;
	}
	auto children = util::getChildren(node);
	for (auto child : children) {
		iterateNode(child, func);
	}
}

std::vector<Node*> Document::getAllNodes() {
	std::vector<Node*> nodes;
	nodes.reserve(idNodeMap_.size());
	iterateNode(this, [&nodes](Node* node) {
		nodes.push_back(node);
		return true;
	});
	return nodes;
}

void Document::builPath() {}

void Document::bindEvents() {
}

void Document::close() {}

Node* Document::getHoverNode() const {
	if (!hover_node_id_.has_value()) {
		return nullptr;
	}
	return getNodeById(hover_node_id_.value()).value();
};

vector<Node*> Document::getSelectedNodes() const {
  vector<Node*> nodes;
  for (const auto& id : selectedNodes_) {
    auto node = getNodeById(id);
    if (node.has_value()) {
      nodes.push_back(node.value());
    }
  }
  return nodes;
};
 
