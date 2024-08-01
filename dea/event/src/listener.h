#pragma once

#include "event.h"

namespace dea::event {

class Listener {
public:
	virtual void onEvent(Event* event) = 0;
};

}