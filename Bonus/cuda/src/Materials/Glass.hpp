/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Glass material
*/


#pragma once

#include "Interfaces/IMaterial.hpp"
#include <cmath>

namespace RayTracer {
    /**
     * @class Glass
     * @brief Represents a glass material in the 3D space.
     *
     * The Glass class is a type of material that has a refractive property. It extends the IMaterial interface.
     */
    class Glass : public IMaterial {

    public:
        /**
         * @brief Constructor for the Glass class.
         *
         * Initializes a new instance of the Glass class with a given refractive index.
         *
         * @param refractionIndex The refractive index of the material.
         */
        Glass(float refractionIndex, Math::Vector3D albedo);

        /**
         * @brief Default destructor for the Glass class.
         */
        ~Glass() = default;

        /**
         * @brief Determines the reflectance of the material.
         *
         * This method calculates the reflectance of the material using the Schlick's approximation.
         *
         * @param cosine The cosine of the angle between the ray and the normal.
         * @param refractionIndex The refractive index of the material.
         * @return The reflectance of the material.
         */
        float schlick(double cosine, float refractionIndex) const;

        /**
         * @brief Determines how a ray interacts with the glass material.
         *
         * This method is called when a ray hits a shape with this material. It calculates the scattered ray and the attenuation.
         *
         * @param ray The incoming ray.
         * @param hit The hit record containing details about the hit.
         * @param attenuation The attenuation of the ray's color due to the material.
         * @param scattered The scattered ray.
         * @return A boolean indicating whether the ray was scattered.
         */
        bool scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation,
                     Math::Ray3D &scattered) const override;

        float refractionIndex; ///< The refractive index of the material. It is a value that determines how much light is bent when it enters the material.
        Math::Vector3D albedo; ///< The albedo of the material. Albedo is the proportion of the light that is reflected by the surface.
    };
}
