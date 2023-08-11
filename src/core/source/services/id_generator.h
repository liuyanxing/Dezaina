#pragma once

#include "desaina_node.h"
#include <stdint.h>
class IdGenerator {
public:
	IdGenerator(uint32_t sessionId): sessionId_(sessionId){};
  GUID genId() {
    GUID id{};
    id.set_sessionID(sessionId_);
    id.set_localID(localId_++);
    return id;
	}
private:
	uint32_t sessionId_;
	uint32_t localId_ = 0;
};