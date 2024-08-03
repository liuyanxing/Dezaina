#include "interaction.h"

namespace dea::interaction {
using namespace event;

void Interaction::onMouseWheel(MouseEvent& event) {
  auto x = event.dx;
  auto y = event.dy;
  // desaina_->viewPort.translate(x * 5, y * 5);
}

void Interaction::onWindowResize(Event& event) {
  // desaina_->viewPort.update();
}

} // namespace interaction