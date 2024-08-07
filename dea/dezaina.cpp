#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "vendor/figma/kiwi.h"
#include "schema/message.h"
#include "dezaina.h"

namespace dea {

using namespace event;

void Dezaina::init() {
	eventSystem_.addListener(&interaction_);
  viewport_.addEventListener(EventType::ViewportChange, [this](event::Event& event) {
    auto matrix = viewport_.getViewMatrix();
    Dezaina::instance().getDocument().handleViewMatrixChange(utility::toMatrix(matrix));
  });
}

}
