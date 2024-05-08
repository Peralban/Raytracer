/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

RayTracer::Translation::Translation()
:   _displacement(0, 0, 0)
{
}

RayTracer::Translation::Translation(const Math::Vector3D &displacement)
:   _displacement(displacement)
{
}

Math::Point3D RayTracer::Translation::transformCoordinates(const Math::Point3D &p)
{
    return p + _displacement;
}

std::optional<Math::Point3D>
RayTracer::Translation::untransformCoordinates(const Math::Point3D &p)
{
    return std::optional<Math::Point3D>(p - _displacement);
}
