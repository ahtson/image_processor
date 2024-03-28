#pragma once

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

struct __attribute__((__packed__)) BMPHeader {
    uint16_t bfType;       // The characters "BM"
    uint32_t bfSize;       // The size of the file in bytes
    uint16_t bfReserved1;  // Unused - must be zero
    uint16_t bfReserved2;  // Unused - must be zero
    uint32_t bfOffBits;    // Offset to start of Pixel Data
};

struct __attribute__((__packed__)) ImageHeader {
    uint32_t biSize;          // Header Size - Must be at least 40
    int32_t biWidth;          // Image width in pixels
    int32_t biHeight;         // Image height in pixels
    uint16_t biPlanes;        // Must be 1
    uint16_t biBitCount;      // Bits per pixel - 1, 4, 8, 16, 24, or 32
    uint32_t biCompression;   // Compression type (0 = uncompressed)
    uint32_t biSizeImage;     // Image Size - may be zero for uncompressed images
    int32_t biXPelsPerMeter;  // Preferred resolution in pixels per meter (horizontal)
    int32_t biYPelsPerMeter;  // Preferred resolution in pixels per meter (vertical)
    uint32_t biClrUsed;       // Number Color Map entries that are actually used
    uint32_t biClrImportant;  // Number of significant colors
};

struct __attribute__((__packed__)) RGB {
    RGB(uint8_t b, uint8_t g, uint8_t r) : blue(b), green(g), red(r){};
    RGB() : RGB(0, 0, 0){};
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

using ColorTable = std::vector<std::vector<RGB>>;

class BitMap;

class PixelMatrix {
public:
    PixelMatrix() = default;
    void Resize(BitMap& bmp, int32_t width, int32_t height);
    void SetPixel(int32_t x, int32_t y, RGB color);
    void SetPixelsMatrix(int32_t height, int32_t width);
    int32_t Width() const;
    int32_t Height() const;
    ColorTable& GetMatrix();
    ColorTable Neighbors(int32_t row, int32_t column);

protected:
    ColorTable bitmap;
};

class BitMap {
public:
    BitMap() = default;
    PixelMatrix& Pixels();
    BMPHeader& GetHeader();
    ImageHeader& GetImageHeader();

protected:
    PixelMatrix bitmap;
    BMPHeader header;
    ImageHeader image_header;
};
