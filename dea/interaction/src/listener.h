#pragma once

#include "event.h"

namespace dea::interaction {

class InteractionListener : public Listener {
public:
	void onEvent(event::Event& event) override {
		switch (event.type) {
			case event::EventType::MouseDown:
				onMouseDown(static_cast<event::MouseDown&>(event));
				break;
			case event::EventType::MouseMove:
				onMouseMove(static_cast<event::MouseMove&>(event));
				break;
			case event::EventType::MouseUp:
				onMouseUp(static_cast<event::MouseUp&>(event));
				break;
		}
	}

protected:
	virtual void onMouseDown(event::MouseDown& event) {};
	virtual void onMouseMove(event::MouseMove& event) {};
	virtual void onMouseUp(event::MouseUp& event) {};
};

} // namespace interaction