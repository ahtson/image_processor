#include "../includes/filters/aging.h"
#include "../includes/matrix/matrix_tools.h"
#include "../includes/util/utils.h"

void AgingFilter::Apply(Parameters& params, BitMap& bmp) {
    const double max_size = 255.0;
    int32_t height = bmp.Pixels().Height();
    int32_t width = bmp.Pixels().Width();
    ColorTable aged(height, std::vector<RGB>(width));
    for (int32_t row = 0; row < height; ++row) {
        for (int32_t col = 0; col < width; ++col) {
            RealRGB aged_pixel;
            RGB pixel = bmp.Pixels().GetMatrix()[row][col];
            aged_pixel.r = pixel.red * c_[0][0] + pixel.green * c_[0][1] + pixel.blue * c_[0][2];
            aged_pixel.g = pixel.red * c_[1][0] + pixel.green * c_[1][1] + pixel.blue * c_[1][2];
            aged_pixel.b = pixel.red * c_[2][0] + pixel.green * c_[2][1] + pixel.blue * c_[2][2];
            aged_pixel.r = Min((aged_pixel.r * d_[0]), max_size);
            aged_pixel.g = Min((aged_pixel.g * d_[1]), max_size);
            aged_pixel.b = Min((aged_pixel.b * d_[2]), max_size);
            double n = static_cast<double>(rand()) / RAND_MAX;
            if (n < eps_) {
                aged_pixel.r = Min(aged_pixel.r * f_[0], max_size);
                aged_pixel.g = Min(aged_pixel.g * f_[1], max_size);
                aged_pixel.b = Min(aged_pixel.b * f_[2], max_size);
            }
            RealRGB temp;
            temp.r = Min(aged_pixel.r * e_[0][0] + aged_pixel.g * e_[0][1] + aged_pixel.b * e_[0][2], max_size);
            temp.g = Min(aged_pixel.r * e_[1][0] + aged_pixel.g * e_[1][1] + aged_pixel.b * e_[1][2], max_size);
            temp.b = Min(aged_pixel.r * e_[2][0] + aged_pixel.g * e_[2][1] + aged_pixel.b * e_[2][2], max_size);
            aged[row][col] = RGB(static_cast<uint8_t>(aged_pixel.b), static_cast<uint8_t>(aged_pixel.g),
                                 static_cast<uint8_t>(aged_pixel.r));
        }
    }
    bmp.Pixels().GetMatrix() = aged;
}
