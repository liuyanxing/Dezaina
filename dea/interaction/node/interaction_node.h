#pragma once

#include "event.h"
#include "base/type.h"

namespace dea::interaction {

class InteractionNode : public event::EventEmitter  {
public:
  void setDirection(base::V2<float> direction) {
		direction_ = direction;
	}

	base::V2<float> getDirection() const {
		return direction_;
	}

private:
  base::V2<float> direction_{1, 1};
};

}