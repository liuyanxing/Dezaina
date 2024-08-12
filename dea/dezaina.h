#pragma once

#include "common/object.h"
#include <cstdint>
#include "event/include/event.h"
#include "viewport/viewport.h"
#include "render.h"
#include "document.h"
#include "interaction.h"

namespace dea {

class Dezaina : public base::NonCopyable {
public:
	Dezaina();
	~Dezaina() {}

	static Dezaina& instance() {
		static Dezaina instance;
		return instance;
	}

	void init();
	bool loadDocument(char* data, size_t size);
	void initViewport(uint32_t width, uint32_t height, float devicePixelRatio);
	void dumpDocument();

	void dispatchEvent(event::Event& event);
  void dispatchMouseEvent(float x, float y, event::EventType type, int button, int buttons);
  void dispatchKeyEvent(event::EventType type, event::KeyCode code, event::KeyMode mode);
  bool isKeyPressed(event::Key code);
	void tick();

  document::Document& getDocument();
  Viewport& getViewport();
  interaction::Interaction& getInteraction();

private:
	document::Document doc_;
	Viewport viewport_;
	render::Render render_;
	event::EventSystem eventSystem_;
	interaction::Interaction interaction_;
};

}