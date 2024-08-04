#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cassert>
#include <variant>
#include "mouse.h"
#include "key.h"
#include "listener.h"
#include "common/array.h"

namespace dea::event {

using EventUnion = std::variant<MouseEvent, KeyEvent>;

class EventSystem {
public:
	void addListener(Listener* listener) {
    listeners_.push_back(listener);
	}

	void dispatchEvent(Event event) {
		if (isStop_) {
			return;
		}

    if (isKey(event)) {
      keyMode_ = event.keyMode;
    }
    event.keyMode = keyMode_;

		if (!events_.full()) {
      if (isMouse(event)) {
        events_.push_back(static_cast<const MouseEvent&>(event));
      } else if (isKey(event)) {
        events_.push_back(static_cast<const KeyEvent&>(event));
      } else {
        assert(false);
      }
		}
	}

	void removeListener(Listener* listener);

	void fireEvent(Event& event) {
    listeners_.forEach([&event](Listener* listener) {
      listener->onEvent(event);
    });
	};

	void fireAllEvents() {
    events_.forEach([this](auto& event) {
      std::visit([this](auto&& arg) { fireEvent(arg); }, event);
    });
    events_.clear();
	};

  void afterTick() {
    Event event;
    event.type = EventType::AfterTick;
    fireEvent(event);
  }

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
	base::array<Listener*, 10> listeners_;
	base::array<EventUnion, 10> events_;
	base::array<uint8_t, 10> keys_;
  KeyMode keyMode_{};
};

}