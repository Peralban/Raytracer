/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Ray3D
*/

#pragma once

#include <optional>
#include "Interfaces/ITransformation.hpp"
#include "Vector3D.hpp"

namespace Raytracer {
    class ITransformation;
}
namespace Math {
    class Vector3D;

    /**
     * @class Ray3D
     * @brief Represents a ray in 3D space.
     *
     * The Ray3D class is used to represent a ray in 3D space, defined by an origin point and a direction vector.
     */
    class Ray3D {
        public:
            /**
             * @brief Default constructor for the Ray3D class.
             *
             * Initializes a new instance of the Ray3D class with default origin and direction.
             */
            Ray3D();

            /**
             * @brief Constructor for the Ray3D class.
             *
             * Initializes a new instance of the Ray3D class with specified origin and direction.
             *
             * @param origin The origin point of the ray.
             * @param direction The direction vector of the ray.
             */
            Ray3D(const Vector3D &origin, const Vector3D &direction);

            /**
             * @brief Default destructor for the Ray3D class.
             */
            ~Ray3D() = default;

            /**
             * @brief Gets the origin of the ray.
             *
             * @return The origin point of the ray.
             */
            Vector3D getOrigin() const;

            /**
             * @brief Gets the direction of the ray.
             *
             * @return The direction vector of the ray.
             */
            Vector3D getDirection() const;

            /**
             * @brief Calculates a point along the ray.
             *
             * This method calculates a point along the ray at a distance t from the origin.
             *
             * @param t The distance from the origin.
             * @return The point on the ray at distance t from the origin.
             */
            Vector3D pointOnRay(double t) const;

            /**
             *  @brief Applies a transformation on a Ray
             *
             * @param tr The transformation to apply
             * @return In a copy, the transformed Ray
            */
            Ray3D transformed(RayTracer::ITransformation &tr) const noexcept;

            /**
             *  @brief Undoes a transformation on a Ray
             *
             * @param tr The transformation to unapply
             * @return In a copy, the untransformed Ray if successful
            */
            std::optional<Ray3D> untransformed(RayTracer::ITransformation &tr) const noexcept;

            Vector3D _origin; ///< The origin point of the ray.
            Vector3D _direction; ///< The direction vector of the ray.

        protected:
        private:
    };
}
