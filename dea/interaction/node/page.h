#pragma once

#include "node.h"
#include "interaction_node.h"


namespace dea::interaction {
class Page : public node::PageNode, public InteractionNode {};

}
