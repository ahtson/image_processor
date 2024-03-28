#pragma once

#include "aging.h"
#include "base.h"
#include "crop.h"
#include "edge.h"
#include "barrel.h"
#include "blur.h"
#include "grayscale.h"
#include "negative.h"
#include "poster.h"
#include "sepia.h"
#include "sharpening.h"

#include "../exceptions/tester.h"

using Filters = std::vector<Filter>;

void ApplyFilters(Filters& filters, BitMap& bmp);