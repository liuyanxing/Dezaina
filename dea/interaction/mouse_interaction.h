#pragma once

#include "selection.h"
#include "node/type.h"
#include "event.h"
#include "utility.h"

namespace dea::interaction {

class MouseInteraction : public InteractionListener {
public:
	MouseInteraction(const Selection& selection) :
		selection_(selection) {}
	void onEvent(event::Event& e) override {
		selection_.onEvent(e);
		InteractionListener::onEvent(e);
	}
private:
	Selection selection_;
	void onMouseDrag(event::MouseEvent& event) override {
		if (selection_.empty() || event.target) {
			return;
		}
		setEventLocalPosition(event, IterWithWorldMatrix(event.target));
		for (auto* node : selection_.getSelection()) {
			auto* emitter = interaction::node_cast<event::EventEmitter*>(node);
			emitter->emit(event);
		}
	}
};

}