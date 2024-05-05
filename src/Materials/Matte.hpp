/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Matte material
*/

#pragma once

#include "Interfaces/IMaterial.hpp"

namespace RayTracer {
    /**
     * @class Matte
     * @brief Represents a matte material in the 3D space.
     *
     * The Matte class is a type of material that has a diffuse reflection. It extends the IMaterial interface.
     */
    class Matte : public IMaterial {
    public:
        /**
         * @brief Constructor for the Matte class.
         *
         * Initializes a new instance of the Matte class with a given albedo.
         *
         * @param albedo The albedo of the material.
         */
        Matte(const Math::Vector3D &albedo);

        /**
         * @brief Default destructor for the Matte class.
         */
        ~Matte() = default;

        /**
         * @brief Determines how a ray interacts with the matte material.
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

        Math::Vector3D _albedo; ///< The albedo of the material. Albedo is the proportion of the light that is reflected by the surface.
    };
}
