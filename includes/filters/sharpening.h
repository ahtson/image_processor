#pragma once

#include "base.h"

class SharpeningFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;

private:
    const Matrix matrix_ = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
};