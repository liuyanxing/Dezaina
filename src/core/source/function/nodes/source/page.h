#pragma once

#include "container_node_base.h"
#include "include/core/SkMatrix.h"

class PageNode : public PageNodeBase, public ContainerNodeBase {
public:
	PageNode() {
		set_type(NodeType::CANVAS);
	};

	const auto& getTransform() const {
		return transform_;
	};

  void setViewMatrix(const SkMatrix& m) {
    transform_ = m;
  } 

private:
	SkMatrix transform_;
};
