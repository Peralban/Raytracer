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
    class MoebiusStrip : public IShape {
    public:
        MoebiusStrip() = default;

        MoebiusStrip(const Math::Vector3D &center, float width, float height, std::shared_ptr<IMaterial> material) :
                _center(center), _width(width), _height(height), _material(material) {}

        ~MoebiusStrip() = default;

        bool hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const override;

    private:
        Math::Vector3D _center;
        float _width;
        float _height;
        std::shared_ptr<IMaterial> _material;
    };
}