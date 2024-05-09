/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** CylinderLimited
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
     * @class CylinderLimited
     * @brief Represents a cylinder in the 3D space.
     *
     * The CylinderLimited class is a type of shape that represents a cylinder in 3D space. It extends the IShape interface.
     */
    class CylinderLimited : public IShape{
    public:
        /**
         * @brief Default constructor for the CylinderLimited class.
         *
         * Initializes a new instance of the CylinderLimited class with default center, radius, height, and material.
         */
        CylinderLimited() = default;

        /**
         * @brief Default destructor for the CylinderLimited class.
         */
        ~CylinderLimited() = default;

        /**
         * @brief Constructor for the CylinderLimited class.
         *
         * Initializes a new instance of the CylinderLimited class with specified center, radius, height, and material.
         *
         * @param center The center of the cylinder.
         * @param radius The radius of the cylinder.
         * @param height The height of the cylinder.
         * @param material The material of the cylinder.
         */
        CylinderLimited(const Math::Vector3D &center, double radius, double height, std::shared_ptr<IMaterial> material);

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

        Math::Vector3D center; ///< The center of the cylinder.
        double radius; ///< The radius of the cylinder.
        double height; ///< The height of the cylinder.
        std::shared_ptr<IMaterial> material; ///< The material of the cylinder.
    };
}
