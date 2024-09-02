#include "dezaina.h"
#ifdef DEA_ENABLE_RENDER
#include "render.h"
#endif

namespace dea {

using namespace event;

void Dezaina::init() {
	eventSystem_.addListener(&interaction_);
  viewport_.addEventListener(EventType::ViewportChange, [this](event::Event& event) {
    auto matrix = viewport_.getViewMatrix();
    Dezaina::instance().getDocument().handleViewMatrixChange(utility::toMatrix(matrix));
  });
}

void Dezaina::tick() {
  if (!doc_.loaded()) {
    return;
  }
  event::Event event{event::EventType::NextTick};
  emit(event);

  eventSystem_.fireAllEvents();
  doc_.flushEditor();
  change_.flush();
  eventSystem_.beforeRender();

#ifdef DEA_ENABLE_RENDER
  render_.render();
#endif

  eventSystem_.afterTick();
}

}
