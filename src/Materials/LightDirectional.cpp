/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light material
*/

#include "LightDirectional.hpp"
#include <iostream>

RayTracer::LightDirectional::LightDirectional(std::shared_ptr<ITextures> color)
    : _color(std::move(color))
{
}

Math::Vector3D RayTracer::LightDirectional::emitted(double uPos, double vPos,
                                                     const Math::Vector3D &p) const
{
    return _color->get(uPos, vPos, p);
}

bool RayTracer::LightDirectional::scatter([[maybe_unused]] const Math::Ray3D &ray,
                                          [[maybe_unused]] const hits &hit,
                                          [[maybe_unused]] Math::Vector3D &attenuation,
                                          [[maybe_unused]] Math::Ray3D &scattered) const
{
    return false;
}
