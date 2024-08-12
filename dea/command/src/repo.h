#pragma once

#include <cassert>
#include <cstddef>
#include <cstring>
#include "primitives.h"
#include "cmd.h"

namespace dea::command {

	template <size_t N>
	class Repo : public CommandArray<N> {
	public:
		Repo() = default;
		~Repo() = default;

		template<typename CmdConfig>
	  auto* getCmd() {
			auto* cmd = find(CmdConfig::id);
			if (!cmd) {
				assert(false);
			}
			return static_cast<Cmd<CmdConfig>>(cmd);
		}

	private:
	};

}