#pragma once

#include "document/include/editor.h"
#include <cstdint>
#include <type_traits>
namespace dea {

using DeaStateFlags = uint8_t;
enum class DeaState : DeaStateFlags {
	IDLE = 1 << 0,
	Select = 1 << 1,
  Edite = 1 << 2,
	EditeText = 1 << 3,
};

inline constexpr DeaStateFlags operator|(DeaState a, DeaState b) {
	return static_cast<uint8_t>(a) | static_cast<uint8_t>(b);
}

}