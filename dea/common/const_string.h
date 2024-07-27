#pragma once

#include <cstddef>

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
	};

}