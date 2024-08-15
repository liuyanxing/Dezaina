
#pragma once

#include "primitives.h"
#include "cmd.h"
#include "repo.h"
#include "vendor/nlohmann/json.hpp"

namespace dea::command {

using json = nlohmann::json;

class Command {
public:
	template<typename CmdConfig>
	static auto Make(const CmdConfig& args) {
		return Cmd{args};
	}

	void init() {
		repo_.clear();
		cmdBuffer_.clear();
		buildDefaultCmd();
	}

	template<typename CmdConfig>
	void addCmdToRepo() {
		repo_.addCmd(Make(CmdConfig{}));
	}

	template<typename CmdConfig>
	auto getCmd() {
		return repo_.getCmd<CmdConfig>();
	}

	void addCmdToExecute(const CmdBase& cmd) {
		cmdBuffer_.addCmd(cmd);
	}

	bool executeAll() {
		bool result = true;
		cmdBuffer_.forEach([this, &result] (const CmdBase& cmd) {
			result = execute(cmd);
		});
		cmdBuffer_.clear();
		return result;
	}

	bool execute(CmdId id, const json& args) {
		auto cmd = repo_.getCmd(id);
		return execute(*cmd);
	}

private:
  Repo<2048> repo_;
	CommandArray<1024> cmdBuffer_;
	bool execute(const CmdBase& cmd, const json& args = nullptr);
	void buildDefaultCmd();
};

}

