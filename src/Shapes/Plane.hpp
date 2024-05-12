/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    /**
     * @class Plane
     * @brief A class representing a plane in 3D space.
     *
     * This class represents a plane in 3D space. It inherits from the IShape interface.
     */
    class Plane : public IShape {
    public:
        /**
         * @brief Default constructor.
         *
         * Initializes a new instance of the Plane class.
         */
        Plane() = default;

        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the Plane class with the given position, normal vector, and material.
         *
         * @param pos The position of the plane.
         * @param norm The normal vector of the plane.
         * @param type The material of the plane.
         */
        Plane(const Math::Vector3D &pos, const Math::Vector3D &norm, std::shared_ptr<IMaterial> type)
            : _position(pos), _normal(norm), _material(type) {}

        /**
         * @brief Default destructor.
         */
        ~Plane();

        /**
         * @brief Determines if a ray hits the plane.
         *
         * This function determines if a given ray hits the plane within a range of t-values.
         *
         * @param ray The ray to check.
         * @param tmin The minimum t-value.
         * @param tmax The maximum t-value.
         * @param hit The hit record to fill with hit information.
         * @return True if the ray hits the plane, false otherwise.
         */
        bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

    private:
        Math::Vector3D _position; ///< The position of the plane.
        Math::Vector3D _normal; ///< The normal vector of the plane.
        std::shared_ptr<IMaterial> _material; ///< The material of the plane.
    };
}
