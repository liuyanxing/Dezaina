#include "desaina_node.h"
#include "page.h"
#include "frame.h"
#include "rectangle.h"
#include <cstddef>
#include <cstdint>
#include <vector>

template<uint32_t NodeSize>
class NodePool {
public:
	NodePool(size_t size) {
		nodes.resize(size);
		for (size_t i = 0; i < size - 1; ++i) {
			nodes[i].next = &nodes[i + 1];
		}
		nodes[size - 1].next = nullptr;
		free_list = &nodes[0];
	};

	// 分配一个node
	void* allocate() {
		if (free_list == nullptr) {
			grow();
		}
		free_list = free_list->next;
		return static_cast<void*>(free_list);
	};
	void grow();
	~NodePool() = default;

private:
	union PoolNode {
		PoolNode* next;
		char data[NodeSize];
	};

  std::vector<PoolNode> nodes;
	PoolNode* free_list = nullptr;
};