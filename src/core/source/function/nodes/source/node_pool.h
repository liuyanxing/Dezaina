#include "class_tool.h"
#include "desaina_node.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"
#include <cstddef>
#include <vector>

constexpr size_t MaxNodeSize = max_size<PageNode, FrameNodeBase, RectangleNode>();
constexpr size_t NodePoolInitialSize = 1024;

union PoolNode {
	PoolNode* next;
	union node {
		PageNode page;
		FrameNodeBase frame;
		RectangleNode rectangle;
	};
};

class NodePool {
public:
	NodePool(size_t size);
	// 分配一个node
	PoolNode* allocate() {
		if (free_list == nullptr) {
			grow();
		}
		free_list = free_list->next;
		return free_list;
	};
	void grow();
	~NodePool() = default;

private:
  std::vector<PoolNode> nodes;
	PoolNode* free_list = nullptr;
};