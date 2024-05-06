/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Colour
*/

#ifndef COLOUR_HPP_
    #define COLOUR_HPP_

    #include <cstdint>

namespace RayTracer {
    class Colour {
        public:
            Colour(
                std::uint8_t r,
                std::uint8_t g,
                std::uint8_t b
            );
            ~Colour() = default;

            std::uint8_t r;
            std::uint8_t g;
            std::uint8_t b;

        protected:
        private:
    };
}

#endif /* !COLOUR_HPP_ */
