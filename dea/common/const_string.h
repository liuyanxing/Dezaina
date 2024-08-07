#pragma once

#include <cstddef>
#include <cstdint>

namespace dea::base {

	template<size_t N = 0>
  struct ConstString {
		constexpr ConstString(const char (&str)[N]) {
			for (size_t i = 0; i < N; ++i) {
				data[i] = str[i];
			}
		}

		char data[N];
		static constexpr size_t length = N;

    consteval uint32_t hash() const {
      // FNV-1 hash
      uint32_t hash = 2166136261;
      for (size_t i = 0; i < N; ++i) {
        hash = (hash * 16777619) ^ data[i];
      }
      return hash;
    }

	};

  template<size_t N>
  consteval uint32_t hash(const char (&str)[N]) {
    return ConstString<N>{str}.hash();
  }

}