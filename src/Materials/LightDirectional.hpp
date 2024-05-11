/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light material
*/

#pragma once

#include "Interfaces/IMaterial.hpp"
#include <cmath>

namespace RayTracer {
    class LightDirectional : public IMaterial {
    public:

        /**
         * @brief Default constructor for the LightDirectional class.
         *
         * Initializes a new instance of the LightDirectional class with default color.
         */
        LightDirectional(const Math::Vector3D &color);

        ~LightDirectional() = default;

        /**
         * @brief Constructor for the LightDirectional class.
         *
         * Initializes a new instance of the LightDirectional class with a given color.
         *
         * @param color The color of the light.
         */
        bool scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const override;

        /**
         * @brief Default destructor for the LightDirectional class.
         */

        Math::Vector3D emitted() const;

    private:
        Math::Vector3D _emit; // The color of the light.
    };
}
