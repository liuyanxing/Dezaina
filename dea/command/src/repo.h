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

		void addCmd(const CmdBase& cmd) {
			auto type = cmd.type;
			indexes_[static_cast<int>(type)] = this->cursor_;
			CommandArray<N>::addCmd(cmd);
		}

		template<typename CmdConfig>
	  auto* getCmd(CmdType type) {
			auto* cmd = reinterpret_cast<CmdBase*>(indexes_[static_cast<int>(type)]);
			if (cmd->type != type) {
				assert(false);
			}
			return static_cast<Cmd<CmdConfig>>(cmd);
		}

	private:
		char* indexes_[static_cast<int>(CmdType::last) + 1];
	};

}