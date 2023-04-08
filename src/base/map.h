#include <optional>
#include "optional"
#include "type_traits"

template<typename T>
std::optional<typename T::mapped_type> getValueFromMap(T& map, typename T::key_type key) {
	std::optional<typename T::mapped_type> value;
	if (map.find(key) != map.end()) {
		value = map[key];
	}
	return value;
}