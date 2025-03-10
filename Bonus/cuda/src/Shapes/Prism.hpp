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
            Prism();

            ~Prism() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;
    };
}
