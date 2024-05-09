/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cylinder
*/

#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Cylinder : public IShape {
        public:
            Cylinder();

            ~Cylinder() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;
    };
}
