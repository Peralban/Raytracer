/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Plane : public IShape {
        public:
            Plane();

            ~Plane() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;
    };
}
