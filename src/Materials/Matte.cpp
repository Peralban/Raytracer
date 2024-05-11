/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Matte material
*/

#include "Matte.hpp"
#include <iostream>

static Math::Vector3D randomInUnitSphere()
{
    Math::Vector3D p;
    do {
        p = Math::Vector3D(drand48(), drand48(), drand48()) * 2.0 - Math::Vector3D(1, 1, 1);
    } while (p.sqLength() >= 1.0);
    return p;
}

RayTracer::Matte::Matte(const Math::Vector3D &albedoValue)
        : albedo(albedoValue)
{
}

bool RayTracer::Matte::scatter([[maybe_unused]] const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const
{
    Math::Vector3D reflectedRay = hit.point + hit.normal + randomInUnitSphere();
    scattered = Math::Ray3D(hit.point, reflectedRay-hit.point);
    attenuation = albedo;
    return true;
}

void RayTracer::Matte::setinfo(const Math::Vector3D &albedoValue)
{
    albedo = albedoValue;
}

extern "C"
{
    RayTracer::Matte *entry_point()
    {
        return new RayTracer::Matte();
    }

    __attribute__((constructor)) void load()
    {
        std::cout << "Loading Matte Material" << std::endl;
    }

    __attribute__((destructor)) void unload()
    {
        std::cout << "Unloading Matte Material" << std::endl;
    }
}
