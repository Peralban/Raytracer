/*
** EPITECH PROJECT, 2024
** ClusterManagement.cpp
** File description:
** DESCRIPTION
*/

#include "ImageLoad.hpp"
#include <stdexcept>

Images::ImageReader::ImageReader(const std::string& imagePath) {
    std::ifstream file(imagePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open or find the image");
    }

    // Read the BMP file header
    unsigned char header[54];
    file.read(reinterpret_cast<char*>(header), 54);

    // Get image dimensions
    _width = *reinterpret_cast<int*>(&header[18]);
    _height = *reinterpret_cast<int*>(&header[22]);

    // Read the image data
    int row_padded = (_width*3 + 3) & (~3);
    unsigned char *data = new unsigned char[row_padded];
    imageData.resize(_height, std::vector<Images::RGB>(_width));

    for (int y = 0; y < _height; ++y) {
        file.read(reinterpret_cast<char*>(data), row_padded);
        for (int x = 0; x < _width; ++x) {
            // BMP stores colors as BGR
            float b = data[x*3 + 0] / 255.0f;
            float g = data[x*3 + 1] / 255.0f;
            float r = data[x*3 + 2] / 255.0f;
            imageData[y][x] = Images::RGB(r, g, b);
        }
    }

    delete[] data;
    file.close();
}

int Images::ImageReader::width() const {
    return _width;
}

int Images::ImageReader::height() const {
    return _height;
}

const Images::RGB & Images::ImageReader::getPixel(int x, int y) const {
    return imageData[y][x];
}

const  std::vector<std::vector<Images::RGB>> &Images::ImageReader::getImageData() const {
    return imageData;
}
