#pragma once

#include "node.h"
#include "rectangle.h"
#include "frame.h"
#include "path.h"
#include "page.h"

namespace dea::interaction {

template <typename T>
T node_cast(node::NodeConstPtr node) {
	using U = std::remove_cv_t<std::remove_pointer_t<T>>;

	if (node->getType() == node::NodeType::CANVAS) {
		if constexpr (std::is_convertible_v<Page, U>) {
			return static_cast<T>((InteractionPath*)(node));
		}
	}

	if (node->getType() == node::NodeType::RECTANGLE) {
		if constexpr (std::is_convertible_v<Rectangle, U>) {
			return static_cast<T>((Rectangle*)(node));
		}
	}

	if (node->getType() == node::NodeType::FRAME) {
		if constexpr (std::is_convertible_v<Frame, U>) {
			return static_cast<T>((Frame*)(node));
		}
	}

	if (node->getType() == node::NodeType::VECTOR) {
		if constexpr (std::is_convertible_v<InteractionPath, U>) {
			return static_cast<T>((InteractionPath*)(node));
		}
	}
  assert(false);
}

}