#pragma once

#include "node.h"
#include "event.h"
#include "interaction_node.h"

namespace dea::interaction {

class Rectangle : public node::RectangleNode, public event::EventEmitter {};

}
