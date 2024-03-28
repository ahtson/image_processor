#pragma once

#include <vector>
#include "../bmp/bmp.h"
#include "../io/parser.h"
#include "../util/utils.h"
#include "../exceptions/exceptions.h"

using Parameters = const std::vector<std::string_view>;
using Filters = std::vector<Filter>;

class BaseFilter {
public:
    virtual void Apply(Parameters& params, BitMap& bmp) = 0;
};
