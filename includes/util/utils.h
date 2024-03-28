#pragma once

#include "bmp/bmp.h"
#include <cstdint>
#include <cmath>

uint8_t NegateColor(uint8_t color);

using Matrix = std::vector<std::vector<int32_t>>;
using Vector = std::vector<double>;

template <typename T>
T Max(T lhs, T rhs) {
    return lhs >= rhs ? lhs : rhs;
}

template <typename T>
T Min(T lhs, T rhs) {
    return lhs >= rhs ? rhs : lhs;
}

struct RealRGB {
    double b = 0;
    double g = 0;
    double r = 0;
};
