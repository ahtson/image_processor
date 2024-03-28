#pragma once

#include "base.h"
#include "../matrix/matrix_tools.h"

class AgingFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;

private:
    const RealMatrix c_ = {{0.393, 0.769, 0.189}, {0.349, 0.686, 0.168}, {0.272, 0.534, 0.131}};
    const Vector d_ = {1.2, 1.1, 1.3};
    const Vector f_ = {1.25, 1.2, 1.15};
    const RealMatrix e_ = {{0.393, 0.769, 0.189}, {0.349, 0.686, 0.168}, {0.272, 0.534, 0.131}};
    const double eps_ = 0.05;
};