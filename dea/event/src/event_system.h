#pragma once

#include <array>
#include <variant>
#include "mouse_event.h"
#include "listener.h"

namespace dea::event {

using EventUnion = std::variant<MouseEvent>;

class EventSystem {
public:
	void addListener(Listener* listener);
	void removeListener(Listener* listener);
	void dispatchEvent(const MouseEvent& event);
	void fireAllEvents();

	bool empty() {
		return events_.empty();
	};

	void stop();
	void start();

private:
  bool isStop_ = false;
	std::array<Listener*, 10> listeners_;
	std::array<EventUnion, 10> events_;
};

}