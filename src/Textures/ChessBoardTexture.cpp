/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "ChessBoardTexture.hpp"
#include <cmath>

RayTracer::ChessBoardTexture::ChessBoardTexture(const Math::Vector3D &color1, const Math::Vector3D &color2, double scale)
{
    _color1 = color1;
    _color2 = color2;
    _scale = scale;
}

Math::Vector3D RayTracer::ChessBoardTexture::get([[maybe_unused]]double u, [[maybe_unused]]double v, const Math::Vector3D &p) const
{
    double sines = sin(_scale * p.x) * sin(_scale * p.y) * sin(_scale * p.z);
    if (sines < 0) {
        return _color1;
    } else {
        return _color2;
    }
}
