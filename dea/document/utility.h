#pragma once

#include "document.h"

namespace dea::document {
	inline node::Matrix getWorldMatrix(node::Node* node) {
		Document::IterWithWorldMatrix iter(node);
		return iter.getWorldMatrix();
	}
}