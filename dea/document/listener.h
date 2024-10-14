#pragma once

#include "event.h"

namespace dea::document {
class Listener {
public:
	void onEvent(event::Event& e) {
		switch (e.type) {
			case event::EventType::PageChange:
				onPageChange(e);
				break;
			default:
				break;
		}
	}

private:
	virtual void onPageChange(event::Event& event) {};
};

} // namespace dea::document