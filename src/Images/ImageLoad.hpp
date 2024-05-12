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
     * @brief A struct representing an RGB color.
     *
     * This struct represents an RGB color with three float values.
     */
    class RGB {
        public:
            float r;
            float g;
            float b;

            RGB(float r, float g, float b) : r(r), g(g), b(b) {}
            RGB() = default;
    };
    /**
     * @class ImageReader
     * @brief A class representing an image reader.
     *
     * The ImageReader class is used to read an image file and store its data.
     */
    class ImageReader {
    public:

        /**
         * @brief Default constructor for the ImageReader class.
         *
         * Initializes a new instance of the ImageReader class.
         */
        ImageReader() = default;

        /**
         * @brief Default destructor for the ImageReader class.
         *
         * Deletes the ImageReader instance.
         */
        ~ImageReader() = default;
        /**
         * @brief Constructor for the ImageReader class.
         *
         * Initializes a new instance of the ImageReader class with a given image path.
         *
         * @param imagePath The path to the image file.
         */
        ImageReader(const std::string& imagePath);

        /**
         * @brief Reads the image file.
         *
         * This method reads the image file and stores its data in the imageData vector.
         */
        const std::vector<std::vector<RGB>>& getImageData() const;

        /**
         * @brief Gets the pixel at a given position.
         *
         * This method gets the pixel at a given position in the image.
         *
         * @param x The x coordinate of the pixel.
         * @param y The y coordinate of the pixel.
         * @return The pixel at the given position.
         */
        const RGB & getPixel(int x, int y) const;

        /**
         * @brief Gets the width of the image.
         *
         * This method gets the width of the image.
         *
         * @return The width of the image.
         */
        int width() const;

        /**
         * @brief Gets the height of the image.
         *
         * This method gets the height of the image.
         *
         * @return The height of the image.
         */
        int height() const;

    private:
        std::vector<std::vector<RGB>> imageData; ///< The image data.
        int _width; ///< The width of the image.
        int _height; ///< The height of the image.
    };
} // namespace Images
