#pragma once

#include "base.h"

class GaussianBlurFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;

private:
    double GaussianDistribution(double, double);
    RGB Normalize(RealRGB pixel);
    std::vector<double> GenerateKernel(int32_t, double);
};
