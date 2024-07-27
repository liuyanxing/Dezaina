#pragma once

#include "document/include/editor.h"
#include <cstdint>
#include <type_traits>
namespace dea {

enum class DeaState : uint8_t {
	IDLE = 1 << 0,
	Select = 1 << 1,
  Edite = 1 << 2,
	EditeText = 1 << 3,
};  

}