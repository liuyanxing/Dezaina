#pragma once

#include "primitives.h"
#include <cstddef>
#include <functional>
#include "prims.h"

namespace dea::command {

class Dezaina;

class CmdBase {
public:
	CmdBase(CmdType type, DeaState condition) : type{type}, condition{condition} {}
	const CmdType type;
	const DeaState condition;
	virtual size_t size() const = 0;
};

template <typename Args, typename Props> 
class Cmd : public CmdBase {
public:

	const Args& data() const {
		return *reinterpret_cast<const Args*>(args_);
	}

	size_t size() const override {
		return sizeof(Cmd<Args, Props>);
	}

private:
friend class Command;
	Cmd(CmdType type, const Props& props, const Args& args, DeaState condition) : CmdBase{type, condition} {
		memcpy(args_, &args, sizeof(Args));
		memcpy(props_, &props, sizeof(Props));
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
		memcpy(cursor_, cmd, size);
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
