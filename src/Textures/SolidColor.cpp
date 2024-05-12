/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SolidColor
*/

#include "SolidColor.hpp"

RayTracer::SolidColor::SolidColor(const Math::Vector3D &color)
{
    _color = color;
}

Math::Vector3D RayTracer::SolidColor::get([[maybe_unused]]double u, [[maybe_unused]]double v, [[maybe_unused]]const Math::Vector3D &p) const
{
    return _color;
}

