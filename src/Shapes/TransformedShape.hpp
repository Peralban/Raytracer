/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** TransformedShape
*/

#ifndef TRANSFORMEDSHAPE_HPP_
    #define TRANSFORMEDSHAPE_HPP_

    #include <memory>
    #include "Interfaces/IShape.hpp"
    #include "Interfaces/ITransformation.hpp"

namespace RayTracer {
    /**
     * @class TransformedShape
     * @brief A class used to apply any transformation to any shape.
     *
     * Instances of this class are constructed from a shape and a transformation,
     * and are themselves a shape with the applied transformation. This class
     * conforms to the Decorator design pattern.
     */
    class TransformedShape : public IShape {
        public:
            /**
             * @brief Constructor that initializes the TransformedShape with a shape and a transformation.
             * @param shape The shape to which the transformation will be applied.
             * @param tr The transformation to be applied to the shape.
             */
            TransformedShape(std::shared_ptr<IShape> shape, std::shared_ptr<ITransformation> tr);

            /**
             * @brief Default destructor.
             */
            ~TransformedShape() = default;

            /**
             * @brief Determines if a ray hits the transformed shape.
             *
             * This function determines if a given ray hits the transformed shape within a range of t-values.
             *
             * @param ray The ray to check.
             * @param tmin The minimum t-value.
             * @param tmax The maximum t-value.
             * @param hit The hit record to fill with hit information.
             * @return True if the ray hits the transformed shape, false otherwise.
             */
            bool hit(const Math::Ray3D &ray, double tmin, double tmax, struct hits &hit) const override;

        protected:
            /**
             * @brief The shape to which the transformation is applied.
             */
            std::shared_ptr<IShape> _shape;

            /**
             * @brief The transformation to be applied to the shape.
             */
            std::shared_ptr<ITransformation> _tr;

        private:
    };
}

#endif /* !TRANSFORMEDSHAPE_HPP_ */
