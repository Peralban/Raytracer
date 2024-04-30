/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** TransformedShape
*/

#ifndef TRANSFORMEDSHAPE_HPP_
    #define TRANSFORMEDSHAPE_HPP_

    #include <memory>
    #include "IShape.hpp"
    #include "ITransformation.hpp"

namespace RayTracer {
    /// @brief Class used to apply any transformation to any shape
    ///
    /// Instances of this class are constructed from a
    /// shape and a transformation, and are themselves a
    /// shape with the applied transformation
    ///
    /// This class conforms to the *Decorator* design pattern
    class TransformedShape : public IShape {
        public:
            TransformedShape(
                std::unique_ptr<IShape> shape,
                std::unique_ptr<ITransformation> tr
            ) : _shape(std::move(shape)), _tr(std::move(tr)) {}
            ~TransformedShape() = default;

            std::optional<Ray> hits(const Ray &ray) override
            {
                std::optional<Ray> transformed_ray = ray.untransformed(*_tr.get());

                if (!transformed_ray) {
                    return std::optional<Ray>();
                }
                std::optional<Ray> hit = _shape->hits(transformed_ray.value());

                if (!hit) {
                    return std::optional<Ray>();
                }
                return std::optional(hit.value().transform(*_tr.get()));
            }

        protected:

            std::unique_ptr<IShape> _shape;
            std::unique_ptr<ITransformation> _tr;
        private:
    };
}

#endif /* !TRANSFORMEDSHAPE_HPP_ */
