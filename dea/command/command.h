
#pragma once

#include "base/const_string.h"
#include "primitives.h"
#include "cmd.h"
#include "repo.h"
// #include "include/nlohmann/json.hpp"

namespace dea::command {

// using json = nlohmann::json;

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
			// result = execute(cmd);
		});
		cmdBuffer_.clear();
		return result;
	}

	bool registerCmd(const std::string& name, const std::string& description, char* args, size_t argsSize, const std::string& condition) {
		// auto size = sizeof(CmdHeader) + name.size() + description.size() + argsSize + condition.size();
		// auto* cmd = new (cursor_) CmdHeader{base::hash(name), size, argsSize,  condition};
		// cursor_ += sizeof(CmdHeader);
		// cmd->name = cursor_;
		// memcpy(cursor_, name.c_str(), name.size());
		// cursor_ += name.size();
		// cmd->description = cursor_;
		// memcpy(cursor_, description.c_str(), description.size());
		// cursor_ += description.size();
		// cmd->args = cursor_;
		// memcpy(cursor_, args, argsSize);
		// cursor_ += argsSize;
		// cmd->condition = cursor_;
		// memcpy(cursor_, condition.c_str(), condition.size());
		// cursor_ += condition.size();
		// return true;
	}

	// bool execute(CmdId id, const json& args) {
	// 	auto cmd = repo_.getCmd(id);
	// 	return execute(*cmd);
	// }

private:
  Repo<2048> repo_;
	 CommandArray<1024> cmdBuffer_;
	// char cmdBuffer_[1024 * 1024];
	//char* cursor_ = cmdBuffer_;
	// bool execute(const CmdBase& cmd, const json& args = nullptr);
	void buildDefaultCmd();
};

}

