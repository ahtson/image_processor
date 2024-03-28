#include "../includes/matrix/matrix_tools.h"

Vector MatrixCalculator::Multiply(ColorTable& neighbors, const Matrix& matrix) {
    const uint8_t max_size = 255;
    double red = 0;
    double green = 0;
    double blue = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            red += neighbors[i][j].red * matrix[i][j];
            blue += neighbors[i][j].blue * matrix[i][j];
            green += neighbors[i][j].green * matrix[i][j];
        }
    }
    red = Min(static_cast<double>(max_size), Max(0.0, red));
    blue = Min(static_cast<double>(max_size), Max(0.0, blue));
    green = Min(static_cast<double>(max_size), Max(0.0, green));
    return {red, blue, green};
}

void MatrixCalculator::EdgeMatrix(BitMap& bmp, const Matrix& matrix, double threshold) {
    const uint8_t max_size = 255;
    ColorTable neighbors;
    Vector ans;
    ColorTable buf = std::vector(bmp.Pixels().Height(), std::vector<RGB>(bmp.Pixels().Width()));
    for (int32_t row = 0; row < bmp.Pixels().Height(); ++row) {
        for (int32_t col = 0; col < bmp.Pixels().Width(); ++col) {
            neighbors = bmp.Pixels().Neighbors(row, col);
            ans = Multiply(neighbors, matrix);
            for (double color : ans) {
                if (color > threshold * max_size) {
                    ans = {1, 1, 1};
                    break;
                } else {
                    ans = {0, 0, 0};
                    break;
                }
            }
            RGB pixel = {static_cast<uint8_t>(ans[2] * max_size), static_cast<uint8_t>(ans[1] * max_size),
                         static_cast<uint8_t>(ans[0] * max_size)};
            buf[row][col] = pixel;
        }
    }
    bmp.Pixels().GetMatrix() = buf;
}

void MatrixCalculator::SharpeningMatrix(BitMap& bmp, const Matrix& matrix) {
    ColorTable neighbors;
    Vector ans;
    ColorTable buf = std::vector(bmp.Pixels().Height(), std::vector<RGB>(bmp.Pixels().Width()));
    for (int32_t row = 0; row < bmp.Pixels().Height(); ++row) {
        for (int32_t col = 0; col < bmp.Pixels().Width(); ++col) {
            neighbors = bmp.Pixels().Neighbors(row, col);
            ans = Multiply(neighbors, matrix);
            RGB pixel = {static_cast<uint8_t>(ans[2]), static_cast<uint8_t>(ans[1]), static_cast<uint8_t>(ans[0])};
            buf[row][col] = pixel;
        }
    }
    bmp.Pixels().GetMatrix() = buf;
}