#pragma once

#include "desaina_node.h"
#include "desaina.h"

namespace desaina_change {
	void createNodeChangeMessage(NodeType type, kiwi::ByteBuffer& buffer, Desaina* desaina);
}
