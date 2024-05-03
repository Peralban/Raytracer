/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Sphere
*/

#pragma once

#include <optional>
#include "Vector3D.hpp"
#include "IShape.hpp"
#include <memory>

namespace RayTracer {
    class IMaterial;

    /**
     * @class Sphere
     * @brief Represents a sphere in the 3D space.
     *
     * The Sphere class is a type of shape that represents a sphere in 3D space. It extends the IShape interface.
     */
    class Sphere : public IShape {
        public:
            /**
             * @brief Default constructor for the Sphere class.
             *
             * Initializes a new instance of the Sphere class with default center, radius, and material.
             */
            Sphere() = default;

            /**
             * @brief Constructor for the Sphere class.
             *
             * Initializes a new instance of the Sphere class with specified center, radius, and material.
             *
             * @param center The center of the sphere.
             * @param radius The radius of the sphere.
             * @param material The material of the sphere.
             */
            Sphere(const Math::Vector3D  &center, float radius, IMaterial *material);

            /**
             * @brief Default destructor for the Sphere class.
             */
            ~Sphere() = default;

            /**
             * @brief Determines if a ray hits the sphere.
             *
             * This method is called to check if a ray hits the sphere. If it does, it fills a hits struct with information about the hit.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t value to consider for a hit.
             * @param tmax The maximum t value to consider for a hit.
             * @param hit The hits struct to fill with information about the hit.
             * @return A boolean indicating whether the ray hit the sphere.
             */
            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;

            Math::Vector3D _center; ///< The center of the sphere.
            float _radius; ///< The radius of the sphere.
            IMaterial *_material; ///< The material of the sphere.
    };
}
