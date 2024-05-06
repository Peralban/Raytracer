/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** MaterialObject
*/

#ifndef MATERIALOBJECT_HPP_
    #define MATERIALOBJECT_HPP_

    #include <memory>
    #include "Ray.hpp"
    #include "Colour.hpp"
    #include "IShape.hpp"
    #include "IMaterial.hpp"

namespace RayTracer{
    class IMaterial;

    class MaterialObject {
        public:
            MaterialObject(
                std::unique_ptr<IShape> shape,
                std::unique_ptr<IMaterial> material
            );
            ~MaterialObject();

            Colour getColourFromRay(const Ray &ray);

        protected:
        private:
    };
}
#endif /* !MATERIALOBJECT_HPP_ */
