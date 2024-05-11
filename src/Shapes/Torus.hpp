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
            Torus();

            ~Torus() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

            void setinfo(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material);
    };
}
