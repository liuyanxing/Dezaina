#pragma once

#include "desaina_node.h"
#include "ellipse.h"
#include "include/private/base/SkTArray.h"
#include "instance.h"
#include "line.h"
#include "page.h"
#include "frame.h"
#include "polygon.h"
#include "rectangle.h"
#include "star.h"
#include "symbol.h"
#include "text.h"
#include "vector.h"
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include <variant>
#include <vector>

using skia_private::TArray;

using PoolNode = std::variant<void*,
  PageNode, FrameNode, RectangleNode, StarNode, LineNode, PolygonNode, VectorNode, TextNode, EllipseNode, InstanceNode, SymbolNode,
  PageNodeBase, FrameNodeBase, RectangleNodeBase, StarNodeBase, LineNodeBase, PolygonNodeBase, VectorNodeBase, TextNodeBase, EllipseNodeBase>;

class NodePool {
public:
	NodePool(size_t size) {
		nodes_.reserve(size);
	};

	template<typename T>
	T* createNode() {
		PoolNode& node = nodes_.push_back();
		node = T{};
		return &std::get<T>(node);
	};

	void clear() {
		nodes_.clear();
	};

	~NodePool() = default;

private:
	uint32_t free_index = 0;
	TArray<PoolNode> nodes_;
};
