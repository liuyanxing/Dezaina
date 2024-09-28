#pragma once

#include "./event.h"
#include "mouse.h"

namespace dea::event {

class Listener {
public:
	virtual void onEvent(Event& event) = 0;
};

class MouseListener {
public:
	void onEvent(Event& event) {
		switch (event.type) {
			case EventType::MouseDown:
				onMouseDown(static_cast<MouseEvent&>(event));
				break;
			case EventType::MouseMove:
				onMouseMove(static_cast<MouseEvent&>(event));
				break;
			case EventType::MouseUp:
				onMouseUp(static_cast<MouseEvent&>(event));
				break;
      case EventType::MouseWheel:
        onMouseWheel(static_cast<MouseEvent&>(event));
        break;
      case EventType::MouseDrag:
        onMouseDrag(static_cast<MouseEvent&>(event));
        break;
      default:
        break;
		}
	}

protected:
	virtual void onMouseDown(MouseEvent& event) {};
	virtual void onMouseMove(MouseEvent& event) {};
	virtual void onMouseUp(MouseEvent& event) {};
	virtual void onMouseDrag(MouseEvent& event) {};
	virtual void onMouseWheel(MouseEvent& event) {};
};

}