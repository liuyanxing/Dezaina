#pragma once

#include <cmath>

namespace dea::base {

inline int sign(double x) {
    return std::signbit(x) ? -1 : 1;
}

inline bool sameFloat(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

}	// namespace dea::base