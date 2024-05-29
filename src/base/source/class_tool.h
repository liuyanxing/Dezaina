#include <stddef.h>

template <typename T>
static constexpr T static_max(T a, T b) {
    return a < b ? b : a;
}

template <typename T, typename... Ts>
static constexpr T static_max(T a, Ts... bs) {
    return static_max(a, static_max(bs...));
}

template <class... Types>
constexpr size_t max_size() {
    return static_max(sizeof(Types)...);
};

