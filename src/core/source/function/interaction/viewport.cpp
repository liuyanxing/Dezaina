#include "interaction.h"
#include "desaina.h"

void Interaction::handleMouseWheel(MouseEvent* event) {
  auto x = event->deltaX;
  auto y = event->deltaY;
  desaina_->viewPort.translate(x * 5, y * 5);
}

void Interaction::handleWindowResize(Event* event) {
  desaina_->viewPort.update();
}
