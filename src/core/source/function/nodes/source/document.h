#pragma once

#include "desaina_node.h"
#include <cstdint>
#include <vector>
#include <memory>
#include <optional>
#include <functional>
#include <unordered_map>
#include "base/map.h"
#include "base/class_tool.h"
#include "guid.h"
#include "node_pool.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"

constexpr size_t NodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

using Node = BaseNodeMixin;
using NodeMapType = std::unordered_map<GUID, Node*>;

class Document : public DocumentNodeBase
{
public:
	Document();
	~Document();
	void close();

	template<typename T>
	T* createNode() {
		void* ptr = nodePool.allocate();
		new (ptr) T();
		return static_cast<T*>(ptr);
	};

	std::optional<Node*> getNodeById(GUID id) {
		return getValueFromMap(idNodeMap_, id);
	}

	void set_loaded(bool loaded) {
		isLoaded = loaded;
	}
	bool is_loaded() const {
		return isLoaded;
	}
	void addNodeToMap(Node* node) {
		auto guid = node->get_id();
		idNodeMap_[guid] = node;
	}

	void buildDocTree();
	void builPath();

	void iterateNode(Node* node, std::function<bool(Node*)> func);
	void iterateChildren(Node* node, std::function<bool(Node*)> func);

private:
	bool isLoaded = false;
	std::vector<std::shared_ptr<PageNode>> children;
	NodePool<NodeSize> nodePool{NodePoolInitialSize};
	NodeMapType idNodeMap_;
};