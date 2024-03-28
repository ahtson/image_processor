#include "../includes/io/io.h"

void ReadBmp(const std::string& filepath, BitMap& bmp) {
    std::fstream file;
    file.open(filepath, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file to read");
    }
    BMPHeader& header = bmp.GetHeader();
    ImageHeader& image_header = bmp.GetImageHeader();
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.read(reinterpret_cast<char*>(&image_header), sizeof(image_header));
    // TODO: test file
    const std::streamsize padding = (image_header.biWidth & 3);
    bmp.Pixels().SetPixelsMatrix(image_header.biHeight, image_header.biWidth);
    for (int32_t i = image_header.biHeight - 1; i >= 0; --i) {
        for (int32_t j = 0; j < image_header.biWidth; ++j) {
            RGB pixel;
            file.read(reinterpret_cast<char*>(&pixel), sizeof(pixel));
            bmp.Pixels().SetPixel(i, j, pixel);
        }
        file.ignore(padding);
    }
    file.close();
}

void WriteBmp(const std::string& filepath, BitMap& bmp) {
    std::ofstream file;
    file.open(filepath, std::ios_base::out | std::ios_base::binary);
    BMPHeader& header = bmp.GetHeader();
    ImageHeader& image_header = bmp.GetImageHeader();
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file to write");
    }

    file.write(reinterpret_cast<char*>(&header), sizeof(header));
    file.write(reinterpret_cast<char*>(&image_header), sizeof(image_header));

    const std::streamsize padding = image_header.biWidth % 4;
    for (int32_t i = image_header.biHeight - 1; i >= 0; --i) {
        for (int32_t j = 0; j < image_header.biWidth; ++j) {
            file.write(reinterpret_cast<char*>(&bmp.Pixels().GetMatrix()[i][j]),
                       sizeof(bmp.Pixels().GetMatrix()[i][j]));
        }

        char shit[padding + 1];
        file.write(reinterpret_cast<const char*>(&shit), padding);
    }
    file.close();
}
