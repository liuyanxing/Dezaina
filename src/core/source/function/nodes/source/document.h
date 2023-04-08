#pragma once

#include "desaina_node.h"
#include <vector>
#include <memory>
#include <optional>
#include "class_tool.h"
#include "node_pool.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"

constexpr size_t NodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

using Node = BaseNodeMixin;

class Document : public DocumentNodeBase
{
public:
	Document() = default;
	~Document();
	bool load(const uint8_t* buffer, uint32_t size);
	void applyNodeChanges(Desaina_Kiwi::Message message);
	void applyNodeChange(Desaina_Kiwi::NodeChange node_change);
	void close();
	void appendChild(std::shared_ptr<PageNode>& page);

	template<typename T>
	T* createNode() {
		void* ptr = nodePool.allocate();
		new (ptr) T();
		return static_cast<T*>(ptr);
	};

	std::optional<Node*> getNodeById(GUID id) {
	}

private:
	bool isLoaded = false;
	std::vector<std::shared_ptr<PageNode>> children;
	NodePool<NodeSize> nodePool{NodePoolInitialSize};
};