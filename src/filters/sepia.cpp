#include "../includes/filters/sepia.h"

void SepiaFilter::Apply(Parameters& params, BitMap& bmp) {
    for (size_t i = 0; i < bmp.Pixels().Height(); ++i) {
        for (size_t j = 0; j < bmp.Pixels().Width(); ++j) {
            RGB& pixel = bmp.Pixels().GetMatrix()[i][j];
            const double max_size = 255.0;
            const uint8_t red =
                static_cast<uint8_t>(Min(0.393 * pixel.red + 0.769 * pixel.green + 0.189 * pixel.blue, max_size));
            const uint8_t green =
                static_cast<uint8_t>(Min(0.349 * pixel.red + 0.686 * pixel.green + 0.168 * pixel.blue, max_size));
            const uint8_t blue =
                static_cast<uint8_t>(Min(0.272 * pixel.red + 0.534 * pixel.green + 0.131 * pixel.blue, max_size));
            pixel = {blue, green, red};
        }
    }
}