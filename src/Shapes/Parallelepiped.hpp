#pragma once

#include <optional>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"
#include <memory>

namespace RayTracer {
    class IMaterial;

    /**
     * @class Parallelepiped
     * @brief Represents a parallelepiped or a rectangular prism in 3D space.
     *
     * The Parallelepiped class is a type of shape that represents a parallelepiped or a rectangular prism in 3D space. It extends the IShape interface.
     */
    class Parallelepiped : public IShape {
        public:
            /**
             * @brief Default constructor for the Parallelepiped class.
             *
             * Initializes a new instance of the Parallelepiped class with default position, size, and material.
             */
            Parallelepiped() = default;

            /**
             * @brief Constructor for the Parallelepiped class.
             *
             * Initializes a new instance of the Parallelepiped class with specified position, size on each axis, and material.
             *
             * @param position The position of the parallelepiped.
             * @param sizeX The size of the parallelepiped along the x-axis.
             * @param sizeY The size of the parallelepiped along the y-axis.
             * @param sizeZ The size of the parallelepiped along the z-axis.
             * @param material The material of the parallelepiped.
             */
            Parallelepiped(const Math::Vector3D &position, float sizeX, float sizeY, float sizeZ, std::shared_ptr<IMaterial> material);

            /**
             * @brief Default destructor for the Parallelepiped class.
             */
            ~Parallelepiped() = default;

            /**
             * @brief Determines if a ray hits the parallelepiped.
             *
             * This method is called to check if a ray hits the parallelepiped. If it does, it fills a hits struct with information about the hit.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t value to consider for a hit.
             * @param tmax The maximum t value to consider for a hit.
             * @param hit The hits struct to fill with information about the hit.
             * @return A boolean indicating whether the ray hit the parallelepiped.
             */
            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

            Math::Vector3D position;
            float sizeX;
            float sizeY;
            float sizeZ;
            std::shared_ptr<IMaterial> material;
    };
}
