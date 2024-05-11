/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scale
*/

#ifndef SCALE_HPP_
    #define SCALE_HPP_

    #include "Interfaces/ITransformation.hpp"

namespace RayTracer {
    /// @brief Scale transformation class: rotates
    /// a shape according to a scale vector
    class Scale : public ITransformation {
        public:
            /// @brief Default constructor: builds scale
            /// transformation with coordinates of {0, 0, 0}
            Scale();

            /// @brief Constructor for a scale transformation
            /// @param angles The coordinates of this scale
            Scale(const Math::Vector3D &angles);
            ~Scale() = default;

            /// @brief Overriden function describing how this
            ///     scale transforms coordinates
            /// @param p A point in space to transform
            /// @return The transformed point
            Math::Point3D transformCoordinates(const Math::Point3D &p) override final;

            /// @brief Overridden function describing how
            ///     to undo this scale
            /// @param p A point in space to untransform
            /// @return The untransformed space
            virtual std::optional<Math::Point3D>
            untransformCoordinates(const Math::Point3D &p) override final;

            void setinfo(const Math::Point3D &p);

        protected:
            Math::Vector3D _coords;
    };
}
#endif /* !SCALE_HPP_ */
