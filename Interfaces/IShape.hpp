/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#pragma  once

#include "Math/Vector3D.hpp"
#include "Math/Ray3D.hpp"
#include <memory>

namespace RayTracer {
    class IMaterial;

    /**
     * @struct hits
     * @brief Represents the result of a ray hitting a shape.
     *
     * The hits struct contains information about a ray hitting a shape, including the hit point, the normal at the hit point, and the material of the shape.
     */
    class hits {
    public:
        float t; ///< The parameter t from the ray equation that represents the hit point.
        Math:: Vector3D point; ///< The point in 3D space where the ray hit the shape.
        Math::Vector3D normal; ///< The normal vector at the hit point.
        std::shared_ptr<IMaterial> material; ///< The material of the shape that was hit.
    };

    /**
     * @class IShape
     * @brief Represents a shape in the 3D space.
     *
     * The IShape class is an interface that defines the behavior of shapes in the scene.
     * Different types of shapes will implement this interface to provide their own specific behavior.
     */
    class IShape {
        public:
            /**
             * @brief Default constructor for the IShape class.
             *
             * Initializes a new instance of the IShape class.
             */
            IShape() = default;

            /**
             * @brief Default destructor for the IShape class.
             */
            virtual ~IShape() = default;

            /**
             * @brief Determines if a ray hits the shape.
             *
             * This method is called to check if a ray hits the shape. If it does, it fills a hits struct with information about the hit.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t value to consider for a hit.
             * @param tmax The maximum t value to consider for a hit.
             * @param hit The hits struct to fill with information about the hit.
             * @return A boolean indicating whether the ray hit the shape.
             */
            virtual bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const = 0;
    };
}
