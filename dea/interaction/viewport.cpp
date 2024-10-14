#include "dezaina.h"
#include "event.h"
#include "interaction.h"

namespace dea::interaction {
using namespace event;

void Interaction::onMouseWheel(MouseEvent& event) {
  auto scale = 1 + event.dy * 0.1;
  if (event.isPressed<Keymod::Ctrl>()) {
    Dezaina::instance().getViewport().scale(scale, scale, event.worldX, event.worldY);
  }
}

void Interaction::onMouseDrag(MouseEvent& event) {
  auto& dezaina = Dezaina::instance();
  if (dezaina.isKeyPressed(event::Key::Space)) {
    dezaina.getViewport().translate(-event.worldDx, event.dy);
  }
}

} // namespace interaction