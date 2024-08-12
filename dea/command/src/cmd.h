#pragma once

#include "primitives.h"
#include <cstddef>
#include <functional>
#include "prims.h"
#include <cstring>
#include <cassert>

namespace dea::command {

using CmdId = uint32_t;

class Dezaina;

class CmdBase {
public:
	CmdBase(CmdId id, DeaStateFlags condition) : id{id}, condition{condition} {}
	const CmdId id;
	const DeaStateFlags condition;
	size_t size() const {
		return size_;
	}
protected:
	size_t size_;
};

template <typename CmdConfig, typename Args = typename CmdConfig::Args, typename Props = typename CmdConfig::Props> 
class Cmd : public CmdBase {
friend class Command;
public:
	const Args& data() const {
		return *reinterpret_cast<const Args*>(args_);
	}

private:
	Cmd(const CmdConfig &config) : CmdBase{CmdConfig::id, CmdConfig::condition} {
		memcpy(args_, &config.args, sizeof(Args));
		memcpy(props_, &config.props, sizeof(Props));
		size_ = sizeof(Cmd<CmdConfig>);
	}
	alignas(alignof(Args)) char args_[sizeof(Args)];
	alignas(alignof(Props)) char props_[sizeof(Props)];
};

template<size_t N>
class CommandArray {
public:
	void addCmd(const CmdBase& cmd) {
		auto size = cmd.size();
		assert(cursor_ + size < cmdsBuffer_ + N);
		memcpy(cursor_, &cmd, size);
		cursor_ += size;
	}

	void forEach(std::function<void(const CmdBase&)> f) {
		auto* cursor = cmdsBuffer_;
		while (cursor < cursor_) {
			auto* cmd = reinterpret_cast<CmdBase*>(cursor);
			f(*cmd);
			cursor += cmd->size();
		}
	}

	CmdBase* find(CmdId id) {
		auto* cursor = cmdsBuffer_;
		while (cursor < cursor_) {
			auto* cmd = reinterpret_cast<CmdBase*>(cursor);
      if (cmd->id == id) return cmd;
			cursor += cmd->size();
		}
    return nullptr;
	}



	void clear() {
		cursor_ = cmdsBuffer_;
	}
	void empty() const {
		return cursor_ == cmdsBuffer_;
	}

protected:
	char cmdsBuffer_[N];
	char* cursor_ = cmdsBuffer_;
  uint32_t index_ = 0;
};

} // namespace dea::command
