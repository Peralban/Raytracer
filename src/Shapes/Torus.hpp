/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Torus
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Torus : public IShape {
        public:
            Torus() = default;

            Torus();

            ~Torus() = default;

            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;
    };
}
