#include "render_system.h"
#include "event_system/event.h"
#include "event_system/ui_event.h"
#include "canvas.h"
#include "desaina.h"

RenderSystem::RenderSystem(Desaina* desaina) : desaina_(desaina), canvas_(desaina) {
  bindEvents();
}

void RenderSystem::bindEvents() {
  addEventListener(EventType::kWindowResize, [this](const Event* event) {
    const auto& [width, height, devicePixelRatio] = desaina_->getWindowInfo();
    canvas_.onWindowResize(width, height, devicePixelRatio);
  });
}