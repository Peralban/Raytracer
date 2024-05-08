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

        Plane(const Math::Vector3D &pos, const Math::Vector3D &norm, IMaterial *type) :
                _position(pos), _normal(norm), _material(type) {}

        ~Plane();

        bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;

    private:
        Math::Vector3D _position;
        Math::Vector3D _normal;
        IMaterial *_material;
    };
}

