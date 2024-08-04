#include "dezaina.h"
#include "event/src/event.h"
#include "interaction.h"

namespace dea::interaction {
using namespace event;

void Interaction::onMouseWheel(MouseEvent& event) {
  auto scale = 1 + event.clientY * 0.1;
  if (event.isPressed<Keymod::Ctrl>()) {
    Dezaina::instance().getViewport().scale(scale, scale);
  }
}

void Interaction::onWindowResize(Event& event) {
  // desaina_->viewPort.update();
}

} // namespace interaction