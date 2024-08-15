#include "hotkey.h"
#include "common/const_string.h"
#include <algorithm>

namespace dea::hotkey {

	void Hotkey::configFromJson(const json& configs) {
		if (configs.is_array()) {
			for (const auto& item : configs) {
				if (item.is_object()) {
					if (!item.contains("key") || !item.contains("command")) {
						continue;
					}
					auto id = base::hash(item["key"].get<std::string>());
					auto iter = std::find_if(hotkeys.beging(), hotkeys.end(), [id](const HotkeyItem& item) { return item.id == id; });
					auto& hotkeyItem = iter != hotkeys.end() ? *iter : hotkeys.emplace_back();
					hotkeyItem.id = id;
					hotkeyItem.cmdId = base::hash(item["cmdId"].get<std::string>());
					if (item.contains("args")) {
						auto& args = item["args"];
					  auto& a = json::to_cbor(args);
						if (a.size() > HotkeyItem::MaxArgSize) {
							continue;
						}
						std::copy(a.begin(), a.end(), hotkeyItem.args);
					}
				}
			}
		}
	}

  bool Hotkey::fire(const std::string& hotkey) {
		auto id = base::hash(hotkey);
		auto iter = std::find_if(hotkeys.begin(), hotkeys.end(), [id](const HotkeyItem& item) { return item.id == id; });
		if (iter != hotkeys.end()) {
			auto& hotkeyItem = *iter;
			command::execute(hotkeyItem.cmdId, json::from_cbor(hotkeyItem.args));
			return true;
		}
		return false;
	}
}