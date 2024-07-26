
#pragma once

#include "primitives.h"
#include "cmd.h"
#include "repo.h"

namespace dea::command {

class Command {
public:
	template<typename ...T>
	static auto Make(T... args) {
		return Cmd{args...};
	}

	void init() {
		repo_.clear();
		cmdArray_.clear();
		buildDefaultCmd();
	}

	template<typename Props, typename Args>
	void addCmdToRepo(CmdType type, const Props& props, const Args& args, DeaState condition) {
		repo_.addCmd(Make(type, props, args, condition));
	}

	template<typename... T>
	auto getCmd(CmdType type) {
		return repo_.getCmd<T...>(type);
	}

	template<typename... T>
	void addCmdToExecute(const Cmd<T...>& cmd) {
		cmdArray_.addCmd(cmd);
	}

	bool executeAll() {
		bool result = true;
		cmdArray_.forEach([this, &result] (const CmdBase& cmd) {
			result = execute(cmd);
		});
		cmdArray_.clear();
		return result;
	}

private:
  Repo<2048> repo_;
	CommandArray<1024> cmdArray_;
	bool execute(const CmdBase& cmd);
	void buildDefaultCmd();
};

}

