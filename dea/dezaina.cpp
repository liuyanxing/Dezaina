#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "vendor/figma/kiwi.h"
#include "schema/message.h"
#include "dezaina.h"

namespace dea {

void Dezaina::init() {
	eventSystem_.addListener(&interaction_);
}

}
