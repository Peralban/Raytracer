/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ShapeList
*/

#pragma once

#include "Interfaces/IShape.hpp"
#include <vector>
#include <memory>

namespace RayTracer {
    /**
     * @class ShapeList
     * @brief Represents a list of shapes in the 3D space.
     *
     * The ShapeList class is a type of shape that contains a list of other shapes. It extends the IShape interface.
     * It is used to group multiple shapes together and treat them as a single shape for the purpose of hit detection.
     */
    class ShapeList : public IShape {
        public:
            /**
             * @brief Default constructor for the ShapeList class.
             *
             * Initializes a new instance of the ShapeList class with an empty list of shapes.
             */
            ShapeList() = default;

            /**
             * @brief Constructor for the ShapeList class.
             *
             * Initializes a new instance of the ShapeList class with a given list of shapes.
             *
             * @param shapes The list of shapes to initialize the ShapeList with.
             */
            ShapeList(std::vector<std::shared_ptr<IShape>> shapes);

            /**
             * @brief Default destructor for the ShapeList class.
             */
            ~ShapeList() = default;

            /**
             * @brief Determines if a ray hits any shape in the list.
             *
             * This method is called to check if a ray hits any shape in the list. If it does, it fills a hits struct with information about the hit.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t value to consider for a hit.
             * @param tmax The maximum t value to consider for a hit.
             * @param hit The hits struct to fill with information about the hit.
             * @return A boolean indicating whether the ray hit any shape in the list.
             */
            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;

            std::vector<std::shared_ptr<IShape>> shapes; ///< The list of shapes contained in the ShapeList.
    };
}
