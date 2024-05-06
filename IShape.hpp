/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#ifndef ISHAPE_HPP_
    #define ISHAPE_HPP_

    #include <optional>
    #include "Ray.hpp"

namespace RayTracer {
    class IShape {
        public:
            IShape() = default;
            virtual ~IShape() = default;

            /// @brief Function used to describe the shape
            /// @param ray The ray on which to compute a potential collision
            /// @return If the ray doesn't hit the shape: an empty optional
            ///         Otherwise: A ray starting at the impact point with a
            ///           director vector normal to the surface of the shape
            virtual std::optional<Ray> hits(const Ray &ray) = 0;

        protected:
        private:
    };
}
#endif /* !ISHAPE_HPP_ */
