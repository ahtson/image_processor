#pragma once

#include "base.h"

class BarrelDistortionFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};