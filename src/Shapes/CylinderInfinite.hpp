/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** CylinderInfinite
*/

#pragma once


#include <optional>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"
#include <cmath>
#include <memory>

namespace RayTracer {
    class IMaterial;
    /**
     * @class CylinderInfinite
     * @brief Represents a cylinder in the 3D space.
     *
     * The CylinderInfinite class is a type of shape that represents a cylinder in 3D space. It extends the IShape interface.
     */
    class CylinderInfinite : public IShape{
    public:
        /**
         * @brief Default constructor for the CylinderInfinite class.
         *
         * Initializes a new instance of the CylinderInfinite class with default center, radius, and material.
         */
        CylinderInfinite() = default;

        /**
         * @brief Default destructor for the CylinderInfinite class.
         */
        ~CylinderInfinite() = default;

        /**
         * @brief Constructor for the CylinderInfinite class.
         *
         * Initializes a new instance of the CylinderInfinite class with specified center, radius, and material.
         *
         * @param center The center of the cylinder.
         * @param radius The radius of the cylinder.
         * @param material The material of the cylinder.
         */
        CylinderInfinite(const Math::Vector3D &center, double radius, std::shared_ptr<IMaterial> material);

        /**
         * @brief Determines if a ray hits the cylinder.
         *
         * This method is called to check if a ray hits the cylinder. If it does, it fills a hits struct with information about the hit.
         *
         * @param ray The ray to check.
         * @param tmin The minimum t value to consider for a hit.
         * @param tmax The maximum t value to consider for a hit.
         * @param hit The hits struct to fill with information about the hit.
         * @return A boolean indicating whether the ray hit the cylinder.
         */
        bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

        void setinfo(const Math::Vector3D &centerValue, double radiusValue, std::shared_ptr<IMaterial> materialValue);

        Math::Vector3D center; ///< The center of the cylinder.
        double radius; ///< The radius of the cylinder.
        std::shared_ptr<IMaterial> material; ///< The material of the cylinder.
    };
}
