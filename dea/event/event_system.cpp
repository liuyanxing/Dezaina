#include "event_system.h"
#include "emitter.h"
#include "dezaina.h"

namespace dea::event {

	void EventSystem::addEvent(const EventUnion& event) {
		if (!events_.full()) {
			events_.push_back(event);
			if (Dezaina::isImmediate()) {
				Dezaina::instance().flush();
			}
		}
	}

  void EventSystem::handleMouseEvent(MouseEvent& event) {
    if (event.type == EventType::MouseDown) {
      event.dragStartX = event.x;
      event.dragStartY = event.y;
    }

    event.mode = keyMode_;
    if (lastMouseEvent_.has_value()) {
      auto& lastEvent = lastMouseEvent_.value();
      if (event.type == EventType::MouseMove &&
          (lastEvent.type == EventType::MouseDown || lastEvent.type == EventType::MouseDrag)) {
        event.type = EventType::MouseDrag;
        event.dx = event.x - lastEvent.x;
        event.dy = event.y - lastEvent.y;
        event.dragStartX = lastEvent.dragStartX;
        event.dragStartY = lastEvent.dragStartY;
        event.worldDx = event.worldX - lastEvent.worldX;
        event.worldDy = event.worldY - lastEvent.worldY;
      }
    }
    lastMouseEvent_ = event;
    addEvent(event);
	}

  void EventSystem::handleKeyEvent(KeyEvent& event) {
    keyMode_ = event.mode;
    auto& keyEvent = static_cast<KeyEvent&>(event);
    if (event.type == EventType::KeyDown && !keys_.contains(keyEvent.code) && !keys_.full()) {
      keys_.push_back(keyEvent.code);
    } else if (event.type == EventType::KeyUp) {
      keys_.remove(keyEvent.code);
    }
    addEvent(event);
	}

	void EventSystem:: dispatchEvent(Event& event) {
		if (isStop_) {
			return;
		}

    if (isMouse(event)) {
      handleMouseEvent(static_cast<MouseEvent&>(event));
    } else if (isKey(event)) {
      handleKeyEvent(static_cast<KeyEvent&>(event));
    } else {
      assert(false);
    }
	}

}