#pragma once

#include "size.h"
#include "color.h"
#include "common/array.h"
#include <variant>
#include "common/const_string.h"

namespace dea::config {

struct ConfigItem {
  uint32_t id{};
  std::variant<uint32_t, int32_t, float, bool, Color> value{};
};

static inline base::array<ConfigItem, 1024> configs{};

template<typename T>
void addConfig(uint32_t id, const T& value) {
  auto item = ConfigItem{};
  item.id = id;
  item.value = value;
  configs.push_back(item);
}
  
#define CONFIG_PROPERTIES \
  /* name,        defalut value, */\
  x_(InterStrokeWidth, size::Min) \
  x_(InterRadiusCtrlNodeSize, size::Tiny) \
  x_(InterBoundCtrNodeSize, size::Small) \
  x_(InterStrokeColor, color::Primary) \
  
#define x_(name, default_value) static inline auto name = default_value;
  CONFIG_PROPERTIES
#undef x_

 constexpr inline void initConfigs() {
#define x_(name, default_value) addConfig(base::hash(#name), name);
  CONFIG_PROPERTIES
#undef x_
  }
}