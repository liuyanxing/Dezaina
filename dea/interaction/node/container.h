
#pragma once

#include "node.h"
#include "interaction_node.h"
#include "type.h"

namespace dea::interaction {

template<typename T>
void appendChild(T* parent, node::Node* child) {
  interaction::node_cast<InteractionNode>(child)->setParent(parent);
  parent->appendChild(child);
}

}
