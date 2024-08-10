#pragma once

#include "vendor/figma/kiwi.h"
#include "common/const_string.h"
#include "cmd.h"

namespace dea::command {

struct ZoomIn {
	struct Props {
		const char* description = "Zoom in";
	} props;

	struct Args {
		float factor = 1.5;

		void parse(const kiwi::buffer& args) {
			float factor = 1.5;
		}
	} args;

	static constexpr CmdId id = base::hash("ZoomIn");
	static constexpr auto condition = DeaState::Select |  0;
};

} // namespace dea::command
