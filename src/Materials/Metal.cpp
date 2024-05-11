/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Metal material
*/

#include "Metal.hpp"
#include <iostream>

static Math::Vector3D randomInUnitSphere()
{
    Math::Vector3D p;
    do {
        p = Math::Vector3D(drand48(), drand48(), drand48()) * 2.0 - Math::Vector3D(1, 1, 1);
    } while (p.sqLength() >= 1.0);
    return p;
}

RayTracer::Metal::Metal(const Math::Vector3D &a, float f)
        : albedo(a)
{
    if (f < 1)
        _fuzziness = f;
    else
        _fuzziness = 1;
}

bool RayTracer::Metal::scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const
{
    Math::Vector3D reflectedRay = reflect(ray.getDirection().getUnitVector(), hit.normal);
    scattered = Math::Ray3D(hit.point, reflectedRay + randomInUnitSphere() * _fuzziness);
    attenuation = albedo;
    return scattered.getDirection().dot(hit.normal) > 0;
}

void RayTracer::Metal::setinfo(const Math::Vector3D &albedoValue, float fuzziness)
{
    albedo = albedoValue;
    _fuzziness = fuzziness;
}

extern "C"
{
    RayTracer::Metal *entry_point()
    {
        return new RayTracer::Metal();
    }

    __attribute__((constructor)) void load()
    {
        std::cout << "Loading Metal Material" << std::endl;
    }

    __attribute__((destructor)) void unload()
    {
        std::cout << "Unloading Metal Material" << std::endl;
    }
}
