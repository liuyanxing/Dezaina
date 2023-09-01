#pragma once

#include <type_traits>
#include <vector>
#include "desaina_kiwi.h"

template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

template <typename T, typename C>
void applyChangeImpl(T& value, const C& change) {
  if constexpr (std::is_enum_v<T>) {
    value = static_cast<T>(change);
  } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
    value = change;
  } else if constexpr (is_string<T>()) {
    value = change.c_str();
  } else {
    value.applyChange(change);
  }
}

template<typename O, typename T, typename Arg>
void toChangeImpl(O* obj, void (O::*setChangeFunc)(Arg), const T& value, kiwi::MemoryPool& pool) {
  if constexpr (std::is_enum_v<T>) {
    return (obj->*setChangeFunc)((Arg)(value));
  } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
    (obj->*setChangeFunc)(value);
  } else if constexpr (is_string<T>()) {
    (obj->*setChangeFunc)(kiwi::String(value.c_str()));
  } else {
		auto* change = pool.allocate<std::remove_pointer_t<Arg>>();
    value.toChange(*change, pool);
    (obj->*setChangeFunc)(change);
  }
}

template<typename T>
class IVector : public std::vector<T> {
public:
  template<typename N>
  void applyChange(const N& change) {
    std::vector<T>::clear();
    for (auto& item : change) {
      std::vector<T>::push_back(T{});
      auto& value = std::vector<T>::back();
      applyChangeImpl(value, item);
    }
  }

  template<typename F, typename C, typename K>
  void toChange(const C& changes, kiwi::MemoryPool& pool) {
    for (int i = 0; i < std::vector<T>::size(); i++) {
      auto& value = (*this)[i];
      auto& change = changes[i];
      if constexpr (std::is_enum_v<T>) {
        change = static_cast<K>(value);
      } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
        change = value;
      } else {
        value.toChange(change, pool);
      }
    }
  }
};