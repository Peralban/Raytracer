/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ITextures
*/

#include "Math/Vector3D.hpp"

#pragma once

namespace RayTracer {
    class ITextures {
        public:

            /**
             * @brief Default constructor for the ITextures class.
             *
             * Initializes a new instance of the ITextures class.
             *
             * @return A new instance of the ITextures class.
             *
             * @throw None
             */
            ITextures() = default;

            /**
             * @brief Default destructor for the ITextures class.
             *
             * Destroys an instance of the ITextures class.
             *
             * @return None
             *
             * @throw None
             */
            virtual ~ITextures() = default;

            /**
             * @brief Determines the color of the texture at a given point.
             *
             * This method calculates the color of the texture at a given point.
             *
             * @param u The u coordinate of the texture.
             * @param v The v coordinate of the texture.
             * @param p The point at which the texture is calculated.
             * @return The color of the texture at the given point.
             *
             * @throw None
             */
            virtual Math::Vector3D get(double u, double v, const Math::Vector3D &p) const = 0;
    };
}
