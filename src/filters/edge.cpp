#include "../includes/filters/edge.h"
#include "../includes/filters/grayscale.h"
#include "../includes/matrix/matrix_tools.h"

void EdgeDetectionFilter::Apply(Parameters& params, BitMap& bmp) {
    if (params.empty() || params[0].empty()) {
        throw FilterException();
    }
    GrayScaleFilter gs;
    gs.Apply(params, bmp);
    MatrixCalculator mc;
    mc.EdgeMatrix(bmp, matrix_, std::stod(std::string(params[0])));
}