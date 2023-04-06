#include "node_pool.h"

NodePool::NodePool(size_t size) {
	nodes.resize(size);
	for (size_t i = 0; i < size - 1; ++i) {
		nodes[i].next = &nodes[i + 1];
	}
	nodes[size - 1].next = nullptr;
	free_list = &nodes[0];
}

void NodePool::grow() {
	size_t old_size = nodes.size();
	size_t new_size = old_size * 2;
	nodes.resize(new_size);
	for (size_t i = old_size; i < new_size - 1; ++i) {
		nodes[i].next = &nodes[i + 1];
	}
	nodes[new_size - 1].next = nullptr;
	free_list = &nodes[old_size];
}