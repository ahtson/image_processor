#include "../includes/util/utils.h"

uint8_t NegateColor(uint8_t colour) {
    const double max_size = 255.0;
    return static_cast<uint8_t>(std::round((1 - (static_cast<double>(colour) / max_size)) * max_size));
}