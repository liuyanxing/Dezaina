#pragma once

#include "primitives.h"
#include <cstddef>
#include <functional>
#include "prims.h"
#include <cstring>
#include <cassert>

namespace dea::command {

class Dezaina;

class CmdBase {
public:
	CmdBase(CmdType type, DeaStateFlags condition) : type{type}, condition{condition} {}
	const CmdType type;
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
	Cmd(const CmdConfig &config) : CmdBase{CmdConfig::type, CmdConfig::condition} {
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
		auto type = cmd.type;
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

	void clear() {
		cursor_ = cmdsBuffer_;
	}
	void empty() const {
		return cursor_ == cmdsBuffer_;
	}

protected:
	char cmdsBuffer_[N];
	char* cursor_ = cmdsBuffer_;
};

} // namespace dea::command
