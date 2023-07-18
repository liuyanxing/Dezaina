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

void Document::consumeEvent(const Event& event) {
  
  if (event.type() <= EventType::MOUSE) {
    consumeMouseEvent(event);
  }
}

void Document::iterateChildrenWithPoint(Node* node, const SkPoint& point, std::function<bool(Node*, type)> func) {
  if (!util::isContainer(node)) {
    return;
  }
  auto container = util::getContainer(node);
  auto child = constainer.getChildWithPoint(point);
  if (!child) {
    return;
  }
  func(child, down);
  iterateChildren(node, point, func)
  func(child, up);
}

void Document::consumeMouseEvent(const Event& event) {

}

void Document::handleMouseDown(const Event& event) {

}

void Document::builPath() {}

void Document::bindEvents() {
  mouseEventEmmiter_.addEventListener<MouseDownEvent>([this](const Event& event) {
    handlehandleMouseDownDown(event);
  });
  mouseEventEmmiter_.addEventListener<MouseDownHover>([this](const Event& event) {
    handlehandleMouseDownDown(event);
  });
}

void Document::close() {}

