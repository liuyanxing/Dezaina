#pragma once

#include <type_traits>
#include <variant>
#include <vector>
#include <variant>

#include "base/buffer.h"
#include "base/type_traits.h"

#include "vendor/figma/kiwi.h"
#include "schema/message.h"

namespace dea::node {

template <typename T, typename C>
void applyChangeImpl(T& value, const C& change) {
  if constexpr (std::is_enum_v<T>) {
    value = static_cast<T>(change);
  } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
    value = change;
  } else if constexpr (base::is_variant<T>()) {
    std::visit([&change](auto &&arg) {
      applyChangeImpl(arg, change);
    }, value);
  } else if constexpr (base::is_string<T>()) {
    value = change.c_str();
  } else if constexpr (base::is_vector<T>()) {
    // vector is like struct, always update all fields
    value.clear();
    using ElemType = typename T::value_type;
    for (auto& item : change) {
      value.push_back(ElemType{});
      auto& v = value.back();
      applyChangeImpl(v, item);
    }
  } 
  else {
    value.applyChange(change);
  }
}

template <>
inline void applyChangeImpl<base::Buffer, kiwi::Array<message::NodeChange>>(base::Buffer& value, const kiwi::Array<message::NodeChange>& change) {
  kiwi::ByteBuffer _bb;
  _bb.writeVarUint(change.size());
  for (auto &_it : change) {
    const_cast<message::NodeChange&>(_it).encode(_bb);
  }
  value.set(_bb.data(), _bb.size());
}


template<typename O, typename T, typename R, typename Arg>
void toChangeImpl(O* obj, R (O::*setChangeFunc)(Arg), const T& value, kiwi::MemoryPool& pool) {
  if constexpr (std::is_enum_v<T>) {
    return (obj->*setChangeFunc)((Arg)(value));
  } else if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
    (obj->*setChangeFunc)(value);
  } else if constexpr (std::is_same_v<T, std::string>) {
    (obj->*setChangeFunc)(kiwi::String(value.c_str()));
  } else {
		auto* change = pool.allocate<std::remove_pointer_t<Arg>>();
    value.toChange(*change, pool);
    (obj->*setChangeFunc)(change);
  }
}

template <typename T, typename U>
void toChangeImpl(T &change, const U& value, kiwi::MemoryPool& pool) {
  if constexpr (std::is_enum_v<U>) {
    change = (T)value;
  } else if constexpr (std::is_integral_v<U> || std::is_floating_point_v<U>) {
    change = (T)value;
  } else if constexpr (std::is_same_v<U, std::string>) {
    change = kiwi::String(value.c_str());
  } else if constexpr (base::is_variant<U>()) {
    std::visit([&change, &pool](auto &&arg) {
      toChangeImpl(change, arg, pool);
    }, value);
  } else if constexpr(base::is_vector<U>()) {
    for (int i = 0; i < value.size(); i++) {
      toChangeImpl(change[i], value[i], pool);
    }
  } else {
    value.toChange(change, pool);
  }
}

template<typename O, typename T, typename R>
void toChangeImpl(O* obj, kiwi::Array<R>& (O::*setChangeFunc)(kiwi::MemoryPool &pool, uint32_t count), T& value, kiwi::MemoryPool& pool) {
  // auto& changes = (obj->*setChangeFunc)(pool, value.size());
  // for (int i = 0; i < value.size(); i++) {
  //   auto& item = value[i];
  //   auto& change = changes[i];
  //   toChangeImpl(change, item, pool);
  // }
}

}