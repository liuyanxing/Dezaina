#pragma once

#include "event.h"

namespace dea::interaction {

class InteractionListener : public event::SystemHookListener {
public:
	void onEvent(event::Event& event) override {
		if (event.isStop()) return;
    event::SystemHookListener::onEvent(event);
		switch (event.type) {
			case event::EventType::MouseDown:
				onMouseDown(static_cast<event::MouseEvent&>(event));
				break;
			case event::EventType::MouseMove:
				onMouseMove(static_cast<event::MouseEvent&>(event));
				break;
			case event::EventType::MouseUp:
				onMouseUp(static_cast<event::MouseEvent&>(event));
				break;
      case event::EventType::MouseWheel:
        onMouseWheel(static_cast<event::MouseEvent&>(event));
        break;
      case event::EventType::MouseDrag:
        onMouseDrag(static_cast<event::MouseEvent&>(event));
        break;
      default:
        break;
		}
	}

protected:
	virtual void onMouseDown(event::MouseEvent& event) {};
	virtual void onMouseMove(event::MouseEvent& event) {};
	virtual void onMouseUp(event::MouseEvent& event) {};
	virtual void onMouseDrag(event::MouseEvent& event) {};
	virtual void onMouseWheel(event::MouseEvent& event) {};
	virtual void onWindowResize(event::Event& event) {};
};

} // namespace interaction