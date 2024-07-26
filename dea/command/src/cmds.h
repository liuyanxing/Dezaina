#pragma once
#include "primitives.h"
#include <algorithm>

#include <cstddef>
#include <string>

namespace dea::command {
	template <size_t T = 0, const char* D> 
	struct ZoomCommand {
		enum Type {
			IN,
			OUT,
			FIT,
			RESET
		};
		struct Props {
			Props() {
				constexpr size_t length = std::char_traits<char>::length(D);
				std::copy(D, D + length, description);
				description[length] = '\0';
			}
			char description[std::char_traits<char>::length(D) + 1];
		};
		struct Args {
			Type type = static_cast<Type>(T);
		};
		CmdType type = CmdType::Zoom;
	};
}