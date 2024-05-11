/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#include "Shapes/Torus.hpp"
#include <iostream>

RayTracer::Torus::Torus() {}


bool RayTracer::Torus::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    (void)ray;
    (void)tmin;
    (void)tmax;
    (void)hit;
    return false;
}

void RayTracer::Torus::setinfo(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material)
{
    (void)origin;
    (void)angle;
    (void)material;
}

extern "C"
{
    RayTracer::Torus *entry_point()
    {
        return new RayTracer::Torus();
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
