#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "vendor/figma/kiwi.h"
#include "schema/message.h"
#include "document/include/document.h"
#include "event/src/event.h"
#include "event/src/event_system.h"
#include "resource/src/resource.h"
#include "viewport/viewport.h"
#include "render.h"
#include "event.h"
#include "interaction.h"

#include "dezaina.h"

namespace dea {

using namespace event;

Dezaina::Dezaina()  : doc_(0), viewport_(), render_(doc_, viewport_) {
  resource::Resource::Init();
  init();
}

void Dezaina::init() {
	eventSystem_.addListener(&interaction_);
  viewport_.addEventListener(EventType::ViewportChange, [this](event::Event& event) {
    auto matrix = viewport_.getViewMatrix();
    Dezaina::instance().getDocument().handleViewMatrixChange(utility::toMatrix(matrix));
  });
}

bool Dezaina::loadDocument(char* data, size_t size) {
  auto res = doc_.load(data, size);
  doc_.dump();
  if (res) {
    // render_.init();
    eventSystem_.start();
  }
  return res;
}

void Dezaina::initViewport(uint32_t width, uint32_t height, float devicePixelRatio) {
  viewport_.update(width, height, devicePixelRatio);
}


void Dezaina::dumpDocument() {
  doc_.dump();
}

	void Dezaina::dispatchEvent(event::Event& event) {
    if (event::isMouse(event)) {
      auto& mouseEvent = static_cast<event::MouseEvent&>(event);
      auto worldCoord = viewport_.mapScreenToWorld(mouseEvent.clientX, mouseEvent.clientY);
      mouseEvent.worldX = worldCoord.x();
      mouseEvent.worldY = worldCoord.y();
    }
    eventSystem_.dispatchEvent(event);
	}

  void Dezaina::dispatchMouseEvent(float x, float y, event::EventType type, int button, int buttons) {
    auto event = event::MouseEvent::Make(x, y, type, button, buttons);
    auto worldCoord = viewport_.mapScreenToWorld(event.clientX, event.clientY);
    event.worldX = worldCoord.x();
    event.worldY = worldCoord.y();
    eventSystem_.dispatchEvent(event);
  }

  void Dezaina::dispatchKeyEvent(event::EventType type, event::KeyCode code, event::KeyMode mode) {
    auto event = event::KeyEvent::Make(type, code, mode);
    eventSystem_.dispatchEvent(event);
  }

  bool Dezaina::isKeyPressed(event::Key code) {
    return eventSystem_.isKeyPressed(code);
  }

	void Dezaina::tick() {
    if (!doc_.loaded()) {
			return;
    }
		eventSystem_.fireAllEvents();
    render_.render();
    eventSystem_.afterTick();
	}

  document::Document& Dezaina::getDocument() {
    return doc_;
  }

  Viewport& Dezaina::getViewport() {
    return viewport_;
  }

  interaction::Interaction& Dezaina::getInteraction() {
    return interaction_;
  }



}  // namespace dea
