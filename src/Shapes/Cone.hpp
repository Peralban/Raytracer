/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    /**
     * @class Cone
     * @brief A class representing a cone shape in 3D space.
     *
     * This class represents a cone shape in 3D space. It inherits from the IShape interface.
     */
    class Cone : public IShape {
        public:
            /**
             * @brief Default constructor.
             *
             * Initializes a new instance of the Cone class.
             */
            Cone() = default;

            /**
             * @brief Parameterized constructor.
             *
             * Initializes a new instance of the Cone class with the given origin, angle, and material.
             *
             * @param origin The origin of the cone.
             * @param angle The angle of the cone.
             * @param material The material of the cone.
             */
            Cone(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material);

            /**
             * @brief Default destructor.
             */
            ~Cone() = default;

            /**
             * @brief Determines if a ray hits the cone.
             *
             * This function determines if a given ray hits the cone within a range of t-values.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t-value.
             * @param tmax The maximum t-value.
             * @param hit The hit record to fill with hit information.
             * @return True if the ray hits the cone, false otherwise.
             */
            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

        private:
            const Math::Vector3D _origin; ///< The origin of the cone.
            const double _tan; ///< The tangent of the angle of the cone.
            const double _sqtan; ///< The square of the tangent of the angle of the cone.
            std::shared_ptr<IMaterial> _material; ///< The material of the cone.

            /**
             * @brief Gets the normal at a point on the cone.
             *
             * This function calculates and returns the normal vector at a given point on the cone.
             *
             * @param point The point on the cone.
             * @return The normal vector at the given point.
             */
            Math::Vector3D __getNormalAt(const Math::Point3D &point) const noexcept;
    };
}
