/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#pragma once

#include "Interfaces/ITextures.hpp"
#include "Images/ImageLoad.hpp"

namespace RayTracer {
    class FromImage : public ITextures {
    public:

        /**
         * @brief Default constructor for the FromImage class.
         *
         * Initializes a new instance of the FromImage class with default color.
         */
        FromImage() = default;

        /**
         * @brief Constructor for the FromImage class.
         *
         * Initializes a new instance of the FromImage class with a given color.
         *
         * @param imagePath The path to the image file.
         */
        FromImage(const std::string &imagePath);

        /**
         * @brief Default destructor for the FromImage class.
         */
        ~FromImage() = default;

        /**
         * @brief Determines the color of the texture at a given point.
         *
         * This method calculates the color of the texture at a given point.
         *
         * @param u The u coordinate of the texture.
         * @param v The v coordinate of the texture.
         * @param p The point at which the texture is calculated.
         * @return The color of the texture at the given point.
         */
        Math::Vector3D get(double u, double v, const Math::Vector3D &p) const override;

    private:
        Images::ImageReader _image; ///< The image of the texture.
    };
}