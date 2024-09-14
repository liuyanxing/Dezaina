#pragma once

#include "node_base.generated.h"

namespace dea::node {
	using Node = BaseNodeMixin;
	using NodeConstRef = const Node&;
	using NodeRef = Node&;
	using NodeConstPtr = const Node*;
	using NodePtr = Node*;
	using NodeArary = std::vector<Node*>;
	using NodeAraryRef = std::vector<Node*>&;
	using NodeAraryConstRef = const std::vector<Node*>&;
	using NodeIdArray = std::vector<GUID>;

	struct Size {
		float width{};
		float height{};
		bool operator==(const Size& other) const {
			return width == other.width && height == other.height;
		}
	};

}