#include "../includes/filters/poster.h"

void PosterizationFilter::Apply(Parameters& params, BitMap& bmp) {
    if (params.empty() || params[0].empty()) {
        throw FilterException();
    }
    int levels = std::stoi(std::string(params[0]));
    double max_size = 255.0;  // NOLINT
    int32_t height = bmp.Pixels().Height();
    int32_t width = bmp.Pixels().Width();
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            RGB& pixel = bmp.Pixels().GetMatrix()[row][col];
            pixel.red =
                static_cast<uint8_t>(pixel.red / (max_size / levels)) * (static_cast<uint8_t>(max_size) / (levels - 1));
            pixel.green = static_cast<uint8_t>(pixel.green / (max_size / levels)) *
                          (static_cast<uint8_t>(max_size) / (levels - 1));
            pixel.blue = static_cast<uint8_t>(pixel.blue / (max_size / levels)) *
                         (static_cast<uint8_t>(max_size) / (levels - 1));
        }
    }
}