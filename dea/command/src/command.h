
#pragma once

#include "primitives.h"
#include "cmd.h"
#include "repo.h"

namespace dea::command {

class Command {
public:
	template<typename CmdConfig>
	static auto Make(const CmdConfig& args) {
		return Cmd{args};
	}

	void init() {
		repo_.clear();
		cmdArray_.clear();
		buildDefaultCmd();
	}

	template<typename CmdConfig>
	void addCmdToRepo() {
		repo_.addCmd(Make(CmdConfig{}));
	}

	template<typename CmdConfig>
	auto getCmd(CmdType type) {
		return repo_.getCmd<CmdConfig>(type);
	}

	void addCmdToExecute(const CmdBase& cmd) {
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

