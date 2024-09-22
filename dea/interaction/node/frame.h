#pragma once

#include "event.h"
#include "node.h"


namespace dea::interaction {
class Frame : public node::FrameNode, public event::EventEmitter {};

}
