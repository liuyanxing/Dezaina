#pragma once

#include "common/object.h"
#include "document/include/document.h"
#include "document/src/editor.h"
#include "event/src/emitter.h"
#include "event/src/event.h"
#include "event/src/event_system.h"
#include "event/src/primitives.h"
#include "resource/src/resource.h"
#include "spdlog/spdlog.h"
#include "viewport/viewport.h"
#include "render.h"
#include "event.h"
#include "interaction.h"

namespace dea {

class Dezaina : public event::EventEmitter, public base::NonCopyable {
public:
	Dezaina() : doc_(0), viewport_(), render_(doc_, viewport_) {
    resource::Resource::Init();
		init();
	}

	~Dezaina() {}

	static Dezaina& instance() {
		static Dezaina instance;
		return instance;
	}

	static document::Editor& editor() {
		return instance().doc_.editor();
	}

	static document::Document& document() {
		return instance().doc_;
	}

	static Viewport& viewport() {
		return instance().viewport_;
	}

	void init();

	bool loadDocument(char* data, size_t size) {
		auto res = doc_.load(data, size);
		doc_.dump();
		if (res) {
			// render_.init();
			eventSystem_.start();
		}
		return res;
	}

	void initViewport(uint32_t width, uint32_t height, float devicePixelRatio) {
		viewport_.update(width, height, devicePixelRatio);
	}

	void dumpDocument() {
		doc_.dump();
	}

	void dispatchEvent(event::Event& event) {
    if (event::isMouse(event)) {
      auto& mouseEvent = static_cast<event::MouseEvent&>(event);
      auto worldCoord = viewport_.mapScreenToWorld(mouseEvent.clientX, mouseEvent.clientY);
      mouseEvent.worldX = worldCoord.x(); mouseEvent.worldY = worldCoord.y();
			mouseEvent.dx = viewport_.mapScreenToWorld(mouseEvent.dx);
			mouseEvent.dy = viewport_.mapScreenToWorld(mouseEvent.dy);
			spdlog::info("dx: {}, dy: {}", mouseEvent.dx, mouseEvent.dy);
    }
    eventSystem_.dispatchEvent(event);
	}

  void dispatchMouseEvent(float x, float y, event::EventType type, int button, int buttons) {
    auto event = event::MouseEvent::Make(x, y, type, button, buttons);
    auto worldCoord = viewport_.mapScreenToWorld(event.clientX, event.clientY);
    event.worldX = worldCoord.x();
    event.worldY = worldCoord.y();
    eventSystem_.dispatchEvent(event);
  }

  void dispatchKeyEvent(event::EventType type, event::KeyCode code, event::KeyMode mode) {
    auto event = event::KeyEvent::Make(type, code, mode);
    eventSystem_.dispatchEvent(event);
  }

  bool isKeyPressed(event::Key code) {
    return eventSystem_.isKeyPressed(code);
  }

	void nextTick(const event::ListenerFunc& listener) {
		addEventListener(event::EventType::NextTick, listener, true);
	}

	void tick() {
    if (!doc_.loaded()) {
			return;
    }
		event::Event event{event::EventType::NextTick};
		emit(event);

		eventSystem_.fireAllEvents();
		doc_.flushEditor();
		eventSystem_.beforeRender();
    render_.render();
    eventSystem_.afterTick();
	}

  auto& getDocument() {
    return doc_;
  }

  auto& getViewport() {
    return viewport_;
  }

  auto& getInteraction() {
    return interaction_;
  }

private:
	document::Document doc_;
	Viewport viewport_;
	render::Render render_;
	event::EventSystem eventSystem_;
	interaction::Interaction interaction_;
};

}