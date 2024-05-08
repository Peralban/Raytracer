/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scale
*/

#include "Scale.hpp"

RayTracer::Scale::Scale()
:   _coords(0, 0, 0)
{
}

RayTracer::Scale::Scale(const Math::Vector3D &coords)
:   _coords(coords)
{
}

Math::Point3D RayTracer::Scale::transformCoordinates(const Math::Point3D &p)
{
    return {
        p.x * _coords.x,
        p.y * _coords.y,
        p.z * _coords.z
    };
}

std::optional<Math::Point3D>
RayTracer::Scale::untransformCoordinates(const Math::Point3D &p)
{
    if (!_coords.x || !_coords.y || !_coords.z) {
        return std::optional<Math::Point3D>();
    } else {
        return std::optional<Math::Point3D>({
            p.x / _coords.x,
            p.y / _coords.y,
            p.z / _coords.z
        });
    }
}
