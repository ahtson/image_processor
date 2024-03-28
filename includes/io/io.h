#pragma once

#include "../bmp/bmp.h"
#include <fstream>
#include "parser.h"

void ReadBmp(const std::string& filepath, BitMap& bmp);

void WriteBmp(const std::string& filepath, BitMap& bmp);
