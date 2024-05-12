/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#pragma once

#include "Interfaces/ITextures.hpp"

namespace RayTracer {
    class ChessBoardTexture : public ITextures {
    public:

        /**
         * @brief Default constructor for the ChessBoardTexture class.
         *
         * Initializes a new instance of the ChessBoardTexture class with default colors.
         */
        ChessBoardTexture() = default;

        /**
         * @brief Constructor for the ChessBoardTexture class.
         *
         * Initializes a new instance of the ChessBoardTexture class with a given colors.
         *
         * @param color1 The first color of the texture.
         * @param color2 The second color of the texture.
         * @param scale The scale of the texture.
         */
        ChessBoardTexture(const Math::Vector3D &color1, const Math::Vector3D &color2, double scale);

        /**
         * @brief Default destructor for the ChessBoardTexture class.
         */
        ~ChessBoardTexture() = default;

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
        Math::Vector3D _color1; ///< The first color of the texture.
        Math::Vector3D _color2; ///< The second color of the texture.
        double _scale; ///< The scale of the texture.
    };
}
