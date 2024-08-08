#pragma once

#include "size.h"
#include "color.h"
#include "common/array.h"
#include <cstddef>
#include <cstdint>
#include <variant>
#include "common/const_string.h"

namespace dea::config {

struct ConfigItem {
  uint32_t id{};
  const char* name;
  std::variant<uint32_t, int32_t, float, bool, Color> value{};
};

static inline base::array<ConfigItem, 1024> configs{};

template<typename T>
T& addConfig(uint32_t id, const char* name, const T& value) {
  auto& item = configs.emplace_back();
  item.id = id;
  item.value = value;
  item.name = name;
  return item.value;
}

template<size_t N, typename T>
void setConfig(const std::string& name, const T& value) {
  uint32_t id = base::hash(name);
  for (auto& item : configs) {
    if (id == item.id) {
      item.value = value;
    }
  }
}
  
#define CONFIG_PROPERTIES \
  /* name,        defalut value, */\
  x_(InterStrokeWidth, size::Min) \
  x_(InterRadiusCtrlNodeSize, size::Tiny) \
  x_(InterBoundCtrNodeSize, size::Small) \
  x_(InterStrokeColor, color::Primary) \
  
#define x_(name, default_value) static inline auto& name = addConfig(base::hash(#name), #name, default_value);
  CONFIG_PROPERTIES
#undef x_

  }

}