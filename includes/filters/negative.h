#pragma once

#include "base.h"

class NegativeFilter : public BaseFilter {
public:
    void Apply(Parameters& params, BitMap& bmp) override;
};