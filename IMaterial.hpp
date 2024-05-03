/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IMaterial
*/

#pragma once

#include "Ray3D.hpp"
#include "IShape.hpp"

namespace RayTracer {
    /**
     * @class IMaterial
     * @brief Represents the material of a shape in the 3D space.
     *
     * The IMaterial class is an interface that defines the behavior of materials in the scene.
     * Different types of materials will implement this interface to provide their own specific behavior.
     */
    class IMaterial {
        public:
            /**
             * @brief Default constructor for the IMaterial class.
             *
             * Initializes a new instance of the IMaterial class.
             */
            IMaterial() = default;

            /**
             * @brief Default destructor for the IMaterial class.
             */
            virtual ~IMaterial() = default;

            /**
             * @brief Determines how a ray interacts with the material.
             *
             * This method is called when a ray hits a shape with this material. It calculates the scattered ray and the attenuation.
             *
             * @param ray The incoming ray.
             * @param hit The hit record containing details about the hit.
             * @param attenuation The attenuation of the ray's color due to the material.
             * @param scattered The scattered ray.
             * @return A boolean indicating whether the ray was scattered.
             */
            virtual bool scatter(const Math::Ray3D &ray, const hits  &hit, Math::Vector3D  &attenuation, Math::Ray3D &scattered) const = 0;
        protected:
        private:
    };
}
