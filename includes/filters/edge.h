#pragma once

#include "base.h"

class EdgeDetectionFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;

private:
    const Matrix matrix_ = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
};