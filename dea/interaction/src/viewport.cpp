#include "interaction.h"
#include "desaina.h"

namespace interaction {

void Interaction::onMouseWheel(MouseEvent* event) {
  auto x = event->deltaX;
  auto y = event->deltaY;
  desaina_->viewPort.translate(x * 5, y * 5);
}

void Interaction::onWindowResize(Event* event) {
  desaina_->viewPort.update();
}

} // namespace interaction