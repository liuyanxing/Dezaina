#pragma once

#include "container_node_base.h"
#include "include/core/SkMatrix.h"

class PageNode : public PageNodeBase, public ContainerNodeBase {
public:
	PageNode() {
		set_type(NodeType::CANVAS);
	};

	auto& view_matrix() {
		return view_matrix_;
	};

private:
	SkMatrix view_matrix_;
};
