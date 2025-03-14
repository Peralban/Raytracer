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
            Obj();

            ~Obj() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;
    };
}
