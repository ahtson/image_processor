#include "../includes/filters/blur.h"
#include <cmath>

double GaussianBlurFilter::GaussianDistribution(double x, double s) {
    const double num = 2.0;
    return exp(-(x * x) / (num * s * s)) / (sqrt(num * M_PI) * s);
}

RGB GaussianBlurFilter::Normalize(RealRGB pixel) {
    return RGB(static_cast<uint8_t>(pixel.b), static_cast<uint8_t>(pixel.g), static_cast<uint8_t>(pixel.r));
}

std::vector<double> GaussianBlurFilter::GenerateKernel(int32_t n, double s) {
    std::vector<double> kernel(n);
    int32_t mid = n / 2;
    for (int32_t i = 0; i < n; ++i) {
        kernel[i] = GaussianDistribution(i - mid, s);
    }
    double sum = 0.0;
    for (int32_t i = 0; i < n; ++i) {
        sum += kernel[i];
    }
    for (int32_t i = 0; i < n; ++i) {
        kernel[i] /= sum;
    }
    return kernel;
}

void GaussianBlurFilter::Apply(Parameters& params, BitMap& bmp) {
    if (params.empty() || params[0].empty()) {
        throw FilterException();
    }
    double s = std::stod(std::string(params[0]));
    int32_t height = bmp.Pixels().Height();
    int32_t width = bmp.Pixels().Width();
    int32_t n = static_cast<int32_t>(2 * ceil(3 * s) + 1);
    std::vector<double> kernel = GenerateKernel(n, s);
    ColorTable blurred_image(height, std::vector<RGB>(width));
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            RealRGB pixel;
            for (int32_t i = 0; i < n; ++i) {
                int idx = col + i - n / 2;
                if (idx < 0) {
                    idx = 0;
                }
                if (idx >= width) {
                    idx = width - 1;
                }
                pixel.r += kernel[i] * bmp.Pixels().GetMatrix()[row][idx].red;
                pixel.g += kernel[i] * bmp.Pixels().GetMatrix()[row][idx].green;
                pixel.b += kernel[i] * bmp.Pixels().GetMatrix()[row][idx].blue;
            }
            blurred_image[row][col] = Normalize(pixel);
        }
    }
    ColorTable result(height, std::vector<RGB>(width));
    for (int32_t col = 0; col < width; ++col) {
        for (int32_t row = 0; row < height; ++row) {
            RealRGB pixel;
            for (int32_t i = 0; i < n; ++i) {
                int idx = row + i - n / 2;
                if (idx < 0) {
                    idx = 0;
                }
                if (idx >= height) {
                    idx = height - 1;
                }
                pixel.r += kernel[i] * blurred_image[idx][col].red;
                pixel.g += kernel[i] * blurred_image[idx][col].green;
                pixel.b += kernel[i] * blurred_image[idx][col].blue;
            }
            result[row][col] = Normalize(pixel);
        }
    }
    bmp.Pixels().GetMatrix() = result;
}