#include "../includes/bmp/bmp.h"

PixelMatrix& BitMap::Pixels() {
    return bitmap;
}

BMPHeader& BitMap::GetHeader() {
    return header;
}

ImageHeader& BitMap::GetImageHeader() {
    return image_header;
}

void PixelMatrix::Resize(BitMap& bmp, int32_t width, int32_t height) {
    const int32_t cur_width = bmp.Pixels().Width();
    const int32_t cur_height = bmp.Pixels().Height();
    bmp.Pixels().GetMatrix().resize(std::min(cur_height, height));
    for (auto& coloumn : bmp.Pixels().GetMatrix()) {
        coloumn.resize(std::min(cur_width, width));
    }
    bmp.GetImageHeader().biHeight = bmp.Pixels().Height();
    bmp.GetImageHeader().biWidth = bmp.Pixels().Width();
}

void PixelMatrix::SetPixel(int32_t x, int32_t y, RGB color) {
    bitmap[x][y] = color;
}

int32_t PixelMatrix::Width() const {
    return static_cast<int32_t>(bitmap[0].size());
}

int32_t PixelMatrix::Height() const {
    return static_cast<int32_t>(bitmap.size());
}

ColorTable& PixelMatrix::GetMatrix() {
    return bitmap;
}

void PixelMatrix::SetPixelsMatrix(int32_t height, int32_t width) {
    for (int32_t i = 0; i < height; ++i) {
        this->GetMatrix().emplace_back(std::vector<RGB>());
        for (int32_t j = 0; j < width; ++j) {
            this->GetMatrix()[i].push_back(RGB());
        }
    }
}

ColorTable PixelMatrix::Neighbors(int32_t row, int32_t column) {
    ColorTable ans = {{{}, {}, {}}, {{}, {}, {}}, {{}, {}, {}}};

    for (int32_t x = -1; x <= 1; ++x) {
        for (int32_t y = -1; y <= 1; ++y) {
            int32_t x_c = std::min(std::max(row + x, 0), this->Height() - 1);
            int32_t y_c = std::min(std::max(column + y, 0), this->Width() - 1);
            ans[x + 1][y + 1] = this->GetMatrix()[x_c][y_c];
        }
    }
    return ans;
}
