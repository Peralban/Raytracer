/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_

    #include <list>
    #include "Ray.hpp"
    #include "Colour.hpp"
    #include "MaterialObject.hpp"

namespace RayTracer {
    class MaterialObject;

    class IMaterial {
        public:
            IMaterial() = default;
            virtual ~IMaterial() = default;

            virtual Colour getColourAt(
                Ray incident,
                Ray normal,
                const std::list<MaterialObject> objects
            );

        protected:
        private:
    };
}

#endif /* !IMATERIAL_HPP_ */
