#pragma once

#include "base/object.h"
#include "event.h"
#include "resource.h"
#include "spdlog/spdlog.h"
#include "viewport/viewport.h"
#include "render.h"
#include "event.h"
#include "interaction.h"
#include "change/change.h"

namespace dea {

class Dezaina : public event::EventEmitter, public base::NonCopyable {
public:
	Dezaina() : doc_(0), viewport_(), render_(doc_, viewport_), eventSystem_(), interaction_(doc_) {
    resource::Resource::Init();
		init();
		eventSystem_.initialized();
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
      auto worldCoord = viewport_.mapScreenToWorld(mouseEvent.x, mouseEvent.y);
      mouseEvent.worldX = worldCoord.x(); mouseEvent.worldY = worldCoord.y();
			mouseEvent.worldDx = viewport_.mapScreenToWorld(mouseEvent.dx);
			mouseEvent.worldDy = viewport_.mapScreenToWorld(mouseEvent.dy);
    }
    eventSystem_.dispatchEvent(event);
	}

  void dispatchMouseEvent(float x, float y, event::EventType type, int button, int buttons) {
    auto event = event::MouseEvent::Make(x, y, type, button, buttons);
    auto worldCoord = viewport_.mapScreenToWorld(event.x, event.y);
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
		change_.flush();
		eventSystem_.beforeRender();
    render_.render();
    eventSystem_.afterTick();
	}

  auto& getDocument() { return doc_; }
  auto& getViewport() { return viewport_; }
  auto& getInteraction() { return interaction_; }
  auto& getEventSystem() { return eventSystem_; }
	auto& getChange() { return change_; }

private:
	document::Document doc_;
	Viewport viewport_;
	render::Render render_;
	event::EventSystem eventSystem_;
	interaction::Interaction interaction_;
	change::Change change_;
};

}