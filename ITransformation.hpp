/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ITransformation
*/

#ifndef ITRANSFORMATION_HPP_
    #define ITRANSFORMATION_HPP_

    #include <optional>
    #include "Point3D.hpp"

namespace RayTracer {
    class ITransformation {
        public:
            ITransformation() = default;
            virtual ~ITransformation() = default;

            /// @brief Get the transformed coordinates of a point
            /// @param p The point to transform
            /// @return The transformed point
            virtual Math::Point3D transformCoordinates(const Math::Point3D &p) = 0;

            /// @brief Undo a transformation
            /// @param p The transformed point to untransform
            /// @return If possible, the untransformed coordinates
            ///
            /// (Yes, some transformations are not reversible: for example, a
            /// transformation that scales to 0 is not reversible since all
            /// points are transformed to 0;0;0, thus it is not possible
            /// to know where the point was before the
            /// transformation from its 0;0;0 transformed coords)
            virtual std::optional<Math::Point3D>
            untransformCoordinates(const Math::Point3D &p) = 0;

        protected:
        private:
    };
}

#endif /* !ITRANSFORMATION_HPP_ */
