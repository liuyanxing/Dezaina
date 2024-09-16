#include "dezaina.h"

namespace dea {

using namespace event;

void Dezaina::init() {
  eventSystem_.addListener(&interaction_);
  viewport_.addEventListener(EventType::ViewportChange,
                             [this](event::Event &event) {
                               auto matrix = viewport_.getViewMatrix();
                               doc_.handleViewMatrixChange(matrix);
                             });
}

void Dezaina::tick() {
  if (!doc_.loaded()) {
    return;
  }
  event::Event event{event::EventType::NextTick};
  emit(event);

  flush();

  eventSystem_.beforeRender();
#ifdef DEA_EANBLE_RENDER
  render_.render();
#endif

  eventSystem_.afterTick();
}

void Dezaina::flush() {
  eventSystem_.fireAllEvents();
  doc_.flushEditor();
  change_.flush();
}

void Dezaina::completeEvent(event::MouseEvent &e) {
  auto worldCoord = viewport_.mapScreenToWorld(e.x, e.y);
  e.worldX = worldCoord.x;
  e.worldY = worldCoord.y;
  e.worldDx = viewport_.getWorldSize(e.dx);
  e.worldDy = viewport_.getWorldSize(e.dy);
}

void Dezaina::dispatchEvent(event::Event &event) {
  if (event::isMouse(event)) {
    auto &mouseEvent = static_cast<event::MouseEvent &>(event);
    completeEvent(mouseEvent);
  }
  eventSystem_.dispatchEvent(event);
}

} // namespace dea
