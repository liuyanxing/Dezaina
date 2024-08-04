#include "dezaina.h"
#include "event/src/event.h"
#include "interaction.h"

namespace dea::interaction {
using namespace event;

void Interaction::onMouseWheel(MouseEvent& event) {
  auto x = event.clientX;
  auto y = event.clientY;
  if (event.isPressed<Keymod::Ctrl>()) {
    Dezaina::instance().getViewport().scale(1.1, 1.1);
  }
}

void Interaction::onWindowResize(Event& event) {
  // desaina_->viewPort.update();
}

} // namespace interaction