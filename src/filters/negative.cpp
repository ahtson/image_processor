#include "../includes/filters/negative.h"
#include "../includes/util/utils.h"

void NegativeFilter::Apply(Parameters& params, BitMap& bmp) {
    for (size_t i = 0; i < bmp.Pixels().Height(); ++i) {
        for (size_t j = 0; j < bmp.Pixels().Width(); ++j) {
            RGB& pixel = bmp.Pixels().GetMatrix()[i][j];
            uint8_t red = NegateColor(pixel.red);
            uint8_t green = NegateColor(pixel.green);
            uint8_t blue = NegateColor(pixel.blue);
            pixel = {blue, green, red};
        }
    }
}
