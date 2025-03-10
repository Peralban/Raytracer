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
                std::shared_ptr<IShape> shape,
                std::shared_ptr<ITransformation> tr
            );
            ~TransformedShape() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, struct hits &hit) const override;


        protected:
            std::shared_ptr<IShape> _shape;
            std::shared_ptr<ITransformation> _tr;
        private:
    };
}

#endif /* !TRANSFORMEDSHAPE_HPP_ */
