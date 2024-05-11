/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Light material
*/

#include "LightDirectional.hpp"
#include <iostream>


RayTracer::LightDirectional::LightDirectional(const Math::Vector3D &color)
{
    _emit = color;
}

Math::Vector3D RayTracer::LightDirectional::emitted() const
{
    return _emit;
}

bool RayTracer::LightDirectional::scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const
{
    return false;
}
