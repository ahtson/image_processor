#pragma once

#include "base.h"

class CropFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};