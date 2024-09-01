#pragma once

#include "selection.h"
#include "utility/node_utility.h"
#include "node/type.h"
#include "event.h"

namespace dea::interaction {

class MouseInteraction : public InteractionListener {
public:
	MouseInteraction(const GetIntersectBound& getIntersectBound, const utility::NodeIterWithWorldMatrix& iter) :
		selection_(getIntersectBound, iter) {}
private:
	Selection selection_;
	void onMouseDrag(event::MouseEvent& event) override {
		if (selection_.empty()) {
			return;
		}
		for (auto* node : selection_.getSelection()) {
			auto* emitter = interaction::node_cast<event::EventEmitter*>(node);
			emitter->emit(event);
		}
	}
};

}