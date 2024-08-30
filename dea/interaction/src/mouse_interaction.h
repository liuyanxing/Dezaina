#pragma once

#include "selection.h"
#include "utility/node_utility.h"

namespace dea::interaction {

class MouseInteraction : public InteractionListener {
public:
	MouseInteraction(const GetIntersectBound& getIntersectBound, const utility::NodeIterWithWorldMatrix& iter) :
		selection_(getIntersectBound, iter) {}
private:
	Selection selection_;
	void onMouseDrag(event::MouseEvent& event) override;
};

}