#pragma once

#include "base.h"

class SepiaFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};