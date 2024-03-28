#include "../includes/filters/grayscale.h"

void GrayScaleFilter::Apply(Parameters& params, BitMap& bmp) {
    for (size_t i = 0; i < bmp.Pixels().Height(); ++i) {
        for (size_t j = 0; j < bmp.Pixels().Width(); ++j) {
            RGB& pixel = bmp.Pixels().GetMatrix()[i][j];
            const uint8_t gray = static_cast<uint8_t>(0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue);
            pixel = {gray, gray, gray};
        }
    }
}