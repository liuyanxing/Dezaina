#pragma once

#include <cmath>

namespace dea::base {

inline int sign(double x) {
    return std::signbit(x) ? -1 : 1;
}

}	// namespace dea::base