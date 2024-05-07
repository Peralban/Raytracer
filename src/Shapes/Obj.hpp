/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Obj
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Obj : public IShape {
        public:
            Obj() = default;

            Obj();

            ~Obj() = default;

            bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;
    };
}
