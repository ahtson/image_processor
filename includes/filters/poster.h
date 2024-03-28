#pragma once

#include "base.h"

class PosterizationFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};