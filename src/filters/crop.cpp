#include "../includes/filters/crop.h"

void CropFilter::Apply(Parameters& params, BitMap& bmp) {
    if (params.size() < 2 || params[0].empty() || params[1].empty()) {
        throw FilterException();
    }
    int32_t width = std::stoi(std::string(params[0]));
    int32_t height = std::stoi(std::string(params[1]));
    bmp.Pixels().Resize(bmp, width, height);
}