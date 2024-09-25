#pragma once

#include <functional>

namespace base {
	template<typename T, typename U, typename K>
	const U& min(const T& array, const std::function<K(const U& ele)>& getVal) {
		const U& minEle = array[0];
		K minVal = getVal(minEle);
		for (const auto& ele : array) {
			auto val = getVal(ele);
			if (val < minVal) {
				minVal = val;
				minEle = ele;
			}
		}
		return minEle;
	}

}