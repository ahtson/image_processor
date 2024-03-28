#pragma once

#include "../bmp/bmp.h"
#include <cstdint>
#include <vector>
#include "../util/utils.h"

using Matrix = std::vector<std::vector<int32_t>>;
using RealMatrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

class MatrixCalculator {
public:
    void EdgeMatrix(BitMap& bmp, const Matrix& matrix, double threshold);
    void SharpeningMatrix(BitMap& bmp, const Matrix& matrix);

private:
    Vector Multiply(ColorTable& neighbors, const Matrix& matrix);
};