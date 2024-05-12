/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Translation
*/

#ifndef TRANSLATION_HPP_
    #define TRANSLATION_HPP_

    #include "Interfaces/ITransformation.hpp"

/**
 * @namespace RayTracer
 * @brief The main namespace for the ray tracing project.
 * Contains all the classes for the shapes.
 */
namespace RayTracer {
    /// @brief Translation transformation class: moves
    /// a shape according to a translation vector
    class Translation : public ITransformation {
        public:
            /// @brief Default constructor: builds translation
            /// transformation with a displacement of {0, 0, 0}
            Translation();

            /// @brief Constructor for a translation transformation
            /// @param displacement The displacement of this translation
            Translation(const Math::Vector3D &displacement);
            ~Translation() = default;

            /// @brief Overriden function describing how this
            ///     translation transforms coordinates
            /// @param p A point in space to transform
            /// @return The transformed point
            Math::Point3D transformCoordinates(const Math::Point3D &p) override final;

            /// @brief Overridden function describing how
            ///     to undo this translation
            /// @param p A point in space to untransform
            /// @return The untransformed space
            virtual std::optional<Math::Point3D>
            untransformCoordinates(const Math::Point3D &p) override final;

        protected:
            const Math::Vector3D _displacement;

        private:
    };
}
#endif /* !TRANSLATION_HPP_ */
