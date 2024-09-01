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

		CmdBase* getCmd(CmdId id) {
			// auto* cmd = find(id);
			// if (!cmd) {
			// 	assert(false);
			// }
			// return cmd;
			return nullptr;
		}

		template<typename CmdConfig>
	  auto* getCmd() {
			return static_cast<Cmd<CmdConfig>>(getCmd(CmdConfig::id));
		}


	private:
	};

}