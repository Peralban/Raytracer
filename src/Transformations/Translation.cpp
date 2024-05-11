/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"
#include <iostream>

RayTracer::Translation::Translation()
:   _displacement(Math::Vector3D(0, 0, 0))
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

void RayTracer::Translation::setinfo(const Math::Point3D &p)
{
    _displacement = p;
}

extern "C"
{
    RayTracer::Translation *entry_point()
    {
        return new RayTracer::Translation();
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
