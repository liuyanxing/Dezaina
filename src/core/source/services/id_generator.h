#pragma once

#include "desaina_node.h"
#include <stdint.h>
class IdGenerator {
public:
	IdGenerator(uint32_t sessionId): sessionId_(sessionId){};
  GUID genId() {
		return { sessionId_, localId_++ };
	}
private:
	uint32_t sessionId_;
	uint32_t localId_ = 0;
};