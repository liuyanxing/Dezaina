#pragma once

#include "container_node_base.h"
#include "include/core/SkMatrix.h"

class PageNode : public PageNodeBase, public ContainerNodeBase {
public:
	PageNode() {
		set_type(NodeType::CANVAS);
	};

	const auto& getViewMatrix() const {
		return view_matrix_;
	};

  void setViewMatrix(const SkMatrix& m) {
    view_matrix_ = m;
  } 

private:
	SkMatrix view_matrix_;
};
