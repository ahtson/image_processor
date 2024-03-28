#include "../includes/filters/barrel.h"
#include "../includes/util/utils.h"

void BarrelDistortionFilter::Apply(Parameters& params, BitMap& bmp) {
    if (params.empty() || params[0].empty()) {
        throw FilterException();
    }

    double k = std::stod(std::string(params[0]));
    int32_t height = bmp.Pixels().Height();
    int32_t width = bmp.Pixels().Width();
    ColorTable distorted(height, std::vector<RGB>(width));

    // Два числа - координаты центра изображения
    int32_t cx = width >> 1;
    int32_t cy = height >> 1;

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {

            int32_t dx = x - cx;
            int32_t dy = y - cy;

            double r = std::sqrt(dx * dx + dy * dy);
            double r_distorted = r * (1 + k * r * r);

            int32_t x_distorted = Max(Min(static_cast<int32_t>(cx + dx * r_distorted / r), width - 1), 0);
            int32_t y_distorted = Max(Min(static_cast<int32_t>(cy + dy * r_distorted / r), height - 1), 0);

            distorted[y][x] = bmp.Pixels().GetMatrix()[y_distorted][x_distorted];
        }
    }
    bmp.Pixels().GetMatrix() = distorted;
}
