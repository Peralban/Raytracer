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
        Plane() = default;

        Plane(const Math::Vector3D &pos, const Math::Vector3D &norm, std::shared_ptr<IMaterial> type)
            : _position(pos), _normal(norm), _material(type) {}

        ~Plane();

        bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

    private:
        Math::Vector3D _position;
        Math::Vector3D _normal;
        std::shared_ptr<IMaterial> _material;
    };
}
