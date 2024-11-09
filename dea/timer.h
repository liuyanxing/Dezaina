#pragma once
#include <functional>
#include <vector>
#include <ranges>
#include <chrono>

namespace dea {

class Timer {
friend class Handle;
public:
	using ID = unsigned int;
	struct Listener
	{
		ID id;
		uint32_t interval;
		uint64_t timeToCall;
		bool repeat;
		std::function<void()> callback;
	};

	ID setTimeout(std::function<void()> callback, uint32_t ms) {
		return addListener(callback, ms, false);
	}
	ID setInterval(std::function<void()> callback, uint32_t ms) {
		return addListener(callback, ms, true);
	}

	void clearTimer(ID id) {
		std::ranges::remove_if(listeners_, [id](const Listener& listener) {
			return listener.id == id;
		});
	}

	void start() {
		auto now = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		lastTime_ = ms;
		running_ = true;
	}
	void pause() {
		running_ = false;
	}
	void resume() {
		start();
	}
	void reset() {
		steadyTime_ = 0;
	}
	void checkListeners() {
		std::vector<ID> toRemove;
		std::ranges::for_each(listeners_, [&toRemove, this](Listener& listener) {
			if (steadyTime_ >= listener.timeToCall) {
				listener.callback();
				if (listener.repeat) {
					listener.timeToCall = steadyTime_ + listener.interval;
				} 
				toRemove.push_back(listener.id);
			}
		});
		for (auto id : toRemove) {
			clearTimer(id);
		}
	}
	void tick() {
		if (!running_) {
			return;
		};
		auto now = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		steadyTime_ += ms - lastTime_;
		lastTime_ = ms;
		checkListeners();
	}

private:
	std::vector<Listener> listeners_;
	bool running_{false};
	uint64_t steadyTime_{0};
	uint64_t lastTime_{0};

	ID addListener(std::function<void()> callback, uint32_t ms, bool repeat) {
		static ID id = 0;
		listeners_.push_back({id++, ms, steadyTime_ + ms, repeat, callback});
		return id - 1;
	}
};

}