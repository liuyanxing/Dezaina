#pragma once

#include "event.h"
#include "base/type.h"
#include "node/type.generated.h"

namespace dea::interaction {

class InteractionNode : public event::EventEmitter  {
public:
  void setDirection(base::v2<float> direction) {
		direction_ = direction;
	}

	base::v2<float> getDirection() const {
		return direction_;
	}

	void disable() {
		enabled_ = false;
	}
	void enable() {
		enabled_ = true;
	}
	bool isEnable() const {
		return enabled_;
	}
	void layout(node::Node* node) {
		auto* shape = node::node_cast<node::DefaultShapeNode>(node);
		assert(shape);
		auto transform = shape->getTransform();
		auto offset = shape->getSize() * anchor_;
		transform.translate(-offset.x, -offset.y);
		shape->setTransform(transform);
	}

private:
	base::v2<float> direction_{1, 1};
	bool enabled_ = true;
	node::Vector anchor_{0.5, 0.5};
};

}