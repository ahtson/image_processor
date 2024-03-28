#include "../includes/matrix/matrix_tools.h"
#include "../../includes/filters/sharpening.h"

void SharpeningFilter::Apply(Parameters& params, BitMap& bmp) {
    MatrixCalculator mc;
    mc.SharpeningMatrix(bmp, matrix_);
}