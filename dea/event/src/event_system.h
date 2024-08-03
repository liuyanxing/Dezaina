#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <variant>
#include "mouse_event.h"
#include "listener.h"

namespace dea::event {

using EventUnion = std::variant<MouseEvent>;

class EventSystem {
public:
	void addListener(Listener* listener) {
		listeners_[listenerCount_++] = listener;
	}

	void dispatchEvent(const Event& event) {
		if (isStop_) {
			return;
		}

		if (event.type == EventType::MouseDown) {
			events_[eventCount_++] = static_cast<const MouseEvent&>(event);
		}
	}

	void removeListener(Listener* listener);

	void fireEvent(MouseEvent& event) {
    for (int i = 0; i < listenerCount_; i++) {
      listeners_[i]->onEvent(event);
    }
	};

	void fireAllEvents() {
    for (int i = 0; i < eventCount_; i++) {
      std::visit([this](auto&& arg) { fireEvent(arg); }, events_[i]);
    }
		eventCount_ = 0;
	};

	bool empty() {
		return events_.empty();
	};

	void stop() {
		isStop_ = true;
	};

	void start() {
		isStop_ = false;
	};

private:
  bool isStop_ = false;
	uint8_t listenerCount_ = 0;
  uint8_t eventCount_ = 0;
	std::array<Listener*, 10> listeners_;
	std::array<EventUnion, 10> events_;
};

}