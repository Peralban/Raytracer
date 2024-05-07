/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Prism
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Prism : public IShape {
        public:
            Prism() = default;

            Prism();

            ~Prism() = default;

            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;
    };
}
