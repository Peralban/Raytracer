/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Rotation
*/

#ifndef ROTATION_HPP_
    #define ROTATION_HPP_

    #include "Interfaces/ITransformation.hpp"

namespace RayTracer {
    /// @brief Rotation transformation class: rotates
    /// a shape according to a rotation vector
    class Rotation : public ITransformation {
        public:
            /// @brief Default constructor: builds rotation
            /// transformation with angles of {0, 0, 0}
            Rotation();

            /// @brief Constructor for a rotation transformation
            /// @param angles The angles of this rotation
            Rotation(const Math::Vector3D &angles);
            ~Rotation() = default;

            /// @brief Overriden function describing how this
            ///     rotation transforms coordinates
            /// @param p A point in space to transform
            /// @return The transformed point
            Math::Point3D transformCoordinates(const Math::Point3D &p) override final;

            /// @brief Overridden function describing how
            ///     to undo this rotation
            /// @param p A point in space to untransform
            /// @return The untransformed space
            virtual std::optional<Math::Point3D>
            untransformCoordinates(const Math::Point3D &p) override final;

            void setinfo(const Math::Point3D &p);

        protected:
            Math::Vector3D _angles;

        private:
            static constexpr inline void __apply_one_2d_rotation(
                double angle,
                double &local_x,
                double &local_y
            ) noexcept;

            /// @brief Computes the angle of a point in cartesian space
            /// @param x The x coordinate of the point in 2D space
            /// @param y The y coordinate of the point in 2D space
            /// @return The angle of that point in the range [-π, +π]
            static constexpr inline double __get_angle_of_points(
                double x,
                double y
            ) noexcept;

            static constexpr inline double __get_magnitude(
                double x,
                double y,
                double angle
            ) noexcept;
    };
}
#endif /* !ROTATION_HPP_ */
