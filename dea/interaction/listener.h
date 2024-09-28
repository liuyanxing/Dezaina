#pragma once

#include "document/listener.h"
#include "event.h"
#include "dezaina/listener.h"
#include "document.h"

namespace dea::interaction {
class InteractionListener : public event::Listener, public event::MouseListener, public dea::Listener, public document::Listener {
public:
	void onEvent(event::Event& event) override {
		event::MouseListener::onEvent(event);
    dea::Listener::onEvent(event);
		document::Listener::onEvent(event);
	}
};

} // namespace interaction