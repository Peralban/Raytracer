/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cube
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Cube : public IShape {
        public:
            Cube();

            ~Cube() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;
    };
}
