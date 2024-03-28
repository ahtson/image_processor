#include "../includes/io/runner.h"

void Run(Parser& commands) {
    BitMap bmp;
    ReadBmp(std::string(commands.GetInputFile()), bmp);
    ApplyFilters(commands.GetFilters(), bmp);
    WriteBmp(std::string(commands.GetOutputFile()), bmp);
}