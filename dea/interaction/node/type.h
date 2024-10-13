#pragma once

#include "node/node.generated.h"
#include "rectangle.h"
#include "frame.h"

namespace dea::interaction {

template <typename T>
T* node_cast(node::NodeConstPtr node) {
	using U = std::remove_cv_t<std::remove_pointer_t<T>>;

	if (node->getType() == node::NodeType::INTER_RECTANGLE) {
		if constexpr (std::is_convertible_v<Rectangle, U>) {
			return static_cast<T*>((Rectangle*)(node));
		}
	}

	if (node->getType() == node::NodeType::INTER_FRAME) {
		if constexpr (std::is_convertible_v<Frame, U>) {
			return static_cast<T*>((Frame*)(node));
		}
	}

	if (node->getType() == node::NodeType::CANVAS) {
		if constexpr (std::is_convertible_v<node::PageNode, U>) {
			return static_cast<T*>((node::PageNode*)(node));
		}
	}

	return nullptr;
}

}