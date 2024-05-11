/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Scale
*/

#include "Scale.hpp"
#include <iostream>

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

void RayTracer::Scale::setinfo(const Math::Point3D &p)
{
    _coords = p;
}

extern "C"
{
    RayTracer::Scale *entry_point()
    {
        return new RayTracer::Scale();
    }

    __attribute__((constructor)) void load()
    {
        std::cout << "Loading SDL2 Graphic" << std::endl;
    }

    __attribute__((destructor)) void unload()
    {
        std::cout << "Unloading SDL2 Graphic" << std::endl;
    }
}
