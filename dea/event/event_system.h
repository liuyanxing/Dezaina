#pragma once

#include <cassert>
#include <variant>
#include "primitives.h"
#include "mouse.h"
#include "key.h"
#include "listener.h"
#include "base/array.h"
#include <optional>

namespace dea::event {

using EventUnion = std::variant<MouseEvent, KeyEvent>;

class EventSystem {
public:
	void addListener(Listener* listener) {
    listeners_.push_back(listener);
	}

  void addEvent(const EventUnion& event);
  void handleMouseEvent(MouseEvent& event);
  void handleKeyEvent(KeyEvent& event);
	void dispatchEvent(Event& event);
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

  void beforeRender() {
    Event event{EventType::BeforeRender};
    fireEvent(event);
  }

  void afterTick() {
    Event event{EventType::AfterTick};
    fireEvent(event);
  }

  void initialized() {
    Event event{EventType::Initialized};
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

  bool isKeyPressed(Key code) {
    return keys_.contains(static_cast<KeyCode>(code));
  }

private:
  bool isStop_ = false;
	base::array<Listener*, 10> listeners_;
	base::array<EventUnion, 10> events_;
	base::array<KeyCode, 10> keys_;
  KeyMode keyMode_{};
  std::optional<MouseEvent> lastMouseEvent_;
};

}