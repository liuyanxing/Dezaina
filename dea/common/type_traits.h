#pragma once

#include <algorithm>
#include <type_traits>

template <typename T1, typename T2, typename... Ts>
struct max_sizeof_helper {
    static constexpr size_t value = std::max(sizeof(T1), max_sizeof_helper<T2, Ts...>::value);
};

template <typename T1, typename T2>
struct max_sizeof_helper<T1, T2> {
    static constexpr size_t value = std::max(sizeof(T1), sizeof(T2));
};

template <typename T1, typename T2, typename... Ts>
struct max_sizeof {
    using type = typename std::conditional<(max_sizeof_helper<T1, T2>::value > max_sizeof<T2, Ts...>::value),
                                            T1, typename max_sizeof<T2, Ts...>::type>::type;
};

template <typename T1, typename T2>
struct max_sizeof<T1, T2> {
    using type = typename std::conditional<(sizeof(T1) > sizeof(T2)), T1, T2>::type;
};

template <typename T1, typename T2, typename... Ts>
using max_sizeof_t = typename max_sizeof<T1, T2, Ts...>::type;
