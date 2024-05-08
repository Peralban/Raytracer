/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Cone : public IShape {
        public:
            Cone() = default;

            Cone(const Math::Vector3D &center, float radius, float height, IMaterial *material);

            ~Cone() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

        private:
            Math::Vector3D _center;
            float _radius;
            float _height;
            IMaterial *_material;

    };
}
