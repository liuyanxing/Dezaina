#pragma once

#include "container.h"
#include "node-base/node.generated.h"

namespace dea::node {

class PageNode : public PageNodeBase, public Container {
public:
	PageNode() {
		type = NodeType::CANVAS;
	};

	const auto& getTransform() const {
		return transform_;
	};

  void setViewMatrix(const Matrix& m) {
    transform_ = m;
  } 

private:
	Matrix transform_;
};

} // namespace dea::node