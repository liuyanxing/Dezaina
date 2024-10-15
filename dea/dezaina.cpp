#include "dezaina.h"
#include "schema/message.h"

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
#ifdef DEA_ENABLE_RENDER
  render_.render();
#endif

  eventSystem_.afterTick();
}

void Dezaina::flush() {
  eventSystem_.fireAllEvents();
  doc_.flushEditor();
  change_.flush();
  eventSystem_.afterFlushed();
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

bool Dezaina::loadFig(std::span<char> data) {
  auto *cusor = reinterpret_cast<const uint8_t *>(data.data());
  cusor += 12;
  auto schemaSize = *reinterpret_cast<const uint32_t *>(cusor);
  cusor += 4;
  auto schema = kiwi::ByteBuffer(cusor, schemaSize);
  message::BinarySchema binarySchema;
  if (!binarySchema.parse(schema)) {
      assert(false);
      return false;
  }

  cusor += schemaSize;
  auto figSize = *reinterpret_cast<const uint32_t *>(cusor);
  auto fig = kiwi::ByteBuffer(cusor + 4, figSize);

  doc_.load(fig, &binarySchema);
  return true;
}

} // namespace dea
