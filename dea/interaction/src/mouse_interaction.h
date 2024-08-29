#pragma once

#include "selection.h"
#include "utility/node_utility.h"

namespace dea::interaction {

class MouseInteraction {
public:
	MouseInteraction(const GetIntersectBound& getIntersectBound, const utility::NodeIterWithWorldMatrix& iter, bool shouldStopEvent) :
		selection_(getIntersectBound, iter, shouldStopEvent) {}
private:
	Selection selection_;
};

}