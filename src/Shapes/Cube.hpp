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
            Cube() = default;

            Cube();

            ~Cube() = default;

            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;
    };
}
