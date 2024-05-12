/*
** EPITECH PROJECT, 2024
** ClusterManagement.cpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

namespace Images {
    /**
     * @class ImageReader
     * @brief A class representing an image reader.
     *
     * The ImageReader class is used to read an image file and store its data.
     */
    class ImageReader {
    public:
        ImageReader(const std::string& imagePath) {
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
            imageData = new unsigned char[row_padded * _height];

            for (int y = 0; y < _height; ++y) {
                file.read(reinterpret_cast<char*>(imageData + y * row_padded), row_padded);
            }

            file.close();
        }

        ~ImageReader() {
            delete[] imageData;
        }

        int width() const {
            return _width;
        }

        int height() const {
            return _height;
        }

        unsigned char* getImageData() const {
            return imageData;
        }

    private:
        int _width, _height;
        unsigned char* imageData;
    };
} // namespace Images
