/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Shear
*/

#ifndef SHEAR_HPP_
    #define SHEAR_HPP_

    #include "Interfaces/ITransformation.hpp"

namespace RayTracer {
    /// @brief Shear transformation class: rotates
    /// a shape according to a shear vector
    class Shear : public ITransformation {
        public:
            /// @brief Default constructor: builds shear
            /// transformation with coordinates of {0, 0, 0}
            Shear();

            /// @brief Constructor for a shear transformation
            /// @param angles The coordinates of this shear
            Shear(const Math::Vector3D &angles);
            ~Shear() = default;

            /// @brief Overriden function describing how this
            ///     shear transforms coordinates
            /// @param p A point in space to transform
            /// @return The transformed point
            Math::Point3D transformCoordinates(const Math::Point3D &p) override final;

            /// @brief Overridden function describing how
            ///     to undo this shear
            /// @param p A point in space to untransform
            /// @return The untransformed space
            virtual std::optional<Math::Point3D>
            untransformCoordinates(const Math::Point3D &p) override final;

            void setinfo(const Math::Point3D &p);

        protected:
            double _xShear;
            double _yShear;

            double Math::Point3D::*_shear_target;
            double Math::Point3D::*_x_coord;
            double Math::Point3D::*_y_coord;
    };
}
#endif /* !SHEAR_HPP_ */
