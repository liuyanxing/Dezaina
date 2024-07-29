#pragma once

#include "container.h"
#include "node-base/node.generated.h"

namespace dea::node {

class PageNode : public PageNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::CANVAS;
	PageNode() {
		setType(Type);
	};

	const auto& getTransform() const {
		return transform_;
	};

  void setViewMatrix(const Matrix& m) {
    transform_ = m;
  } 

private:
	Matrix transform_{1, 0, 0, 1, 0, 0};
};

} // namespace dea::node