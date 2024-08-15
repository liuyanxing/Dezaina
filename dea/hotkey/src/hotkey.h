#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "base/data.h"
#include "command.h"
#include "vendor/nlohmann/json.hpp"

namespace dea::hotkey {

using HotkeyId = uint32_t;
using json = nlohmann::json;

struct HotkeyItem {
	HotkeyId id;
	command::CmdId cmdId;
	uint8_t args[64] = { 0xFF, 0xFF, 0xFF, 0xFF };
	bool isOwnArgs() {
		return *reinterpret_cast<uint32_t*>(&args) != 0xFFFFFFFF;
	}
	static constexpr size_t MaxArgSize = sizeof(args);
};

class Hotkey {
public:
	void init();
	void setHotkey();
	void unsetHotkey();
  bool fire(const std::string& hotkey);
  bool fire(const std::string& hotkey, const json& args);
	void config(const std::string& hotkey, command::CmdId, const base::Data* args = nullptr);
	void configFromJson(const json& json);

private:
	std::vector<HotkeyItem> hotkeys{1024};
};

}