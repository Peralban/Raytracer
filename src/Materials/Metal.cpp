/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Metal material
*/

#include "Metal.hpp"


static Math::Vector3D randomInUnitSphere()
{
    Math::Vector3D p;
    do {
        p = Math::Vector3D(drand48(), drand48(), drand48()) * 2.0 - Math::Vector3D(1, 1, 1);
    } while (p.sqLength() >= 1.0);
    return p;
}

RayTracer::Metal::Metal(const Math::Vector3D &a, float f)
        : _albedo(a)
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
    attenuation = _albedo;
    return scattered.getDirection().dot(hit.normal) > 0;
}
