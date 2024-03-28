#pragma once

#include "base.h"

class GrayScaleFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};