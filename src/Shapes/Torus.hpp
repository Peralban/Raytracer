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

            Torus(const Math::Vector3D &center, float major_radius, float minor_radius, std::shared_ptr<IMaterial> material);

            ~Torus() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

    private:
        Math::Vector3D _center;
        float _major_radius;
        float _minor_radius;
        std::shared_ptr<IMaterial> _material;
    };
}
