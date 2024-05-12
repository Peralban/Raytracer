/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light material
*/

#pragma once

#include "Interfaces/IMaterial.hpp"
#include "Interfaces/ITextures.hpp"
#include <cmath>

namespace RayTracer {
    class LightDirectional : public IMaterial {
    public:

        /**
         * @brief Default constructor for the LightDirectional class.
         *
         * Initializes a new instance of the LightDirectional class with default color.
         */
        LightDirectional(std::shared_ptr<ITextures> color, double lightIntensity);

        /**
         * @brief Default destructor for the LightDirectional class.
         */
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
         * @brief Determines the emitted light of the material.
         *
         * This method calculates the emitted light of the material.
         *
         * @param uPos The u coordinate of the texture.
         * @param vPos The v coordinate of the texture.
         * @param p The point at which the texture is calculated.
         * @return The emitted light of the material.
         */
        Math::Vector3D emitted(double uPos, double vPos, const Math::Vector3D &p) const override;

        /**
         * @brief Gets the light intensity of the material.
         *
         * This method gets the light intensity of the material.
         *
         * @return The light intensity of the material.
         */
        double getLightIntensity() const;

    private:
        std::shared_ptr<ITextures> _color;
        double _lightIntensity;
    };
}
