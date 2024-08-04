#pragma once

#include "event.h"
#include "node.h"
#include "interaction_node.h"


namespace dea::interaction {
class Page : public node::PageNode, public InteractionNode {};

}
