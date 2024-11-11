#pragma once

#include "event.h"
#include "base/type.h"

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

private:
  base::v2<float> direction_{1, 1};
	bool enabled_ = true;
};

}