/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Matte material
*/

#include "Matte.hpp"


static Math::Vector3D randomInUnitSphere()
{
    Math::Vector3D p;
    do {
        p = Math::Vector3D(drand48(), drand48(), drand48()) * 2.0 - Math::Vector3D(1, 1, 1);
    } while (p.sqLength() >= 1.0);
    return p;
}

RayTracer::Matte::Matte(std::shared_ptr<ITextures> texture)
        : _albedo(std::move(texture))
{
}

bool RayTracer::Matte::scatter([[maybe_unused]] const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const
{
    Math::Vector3D reflectedRay = hit.point + hit.normal + randomInUnitSphere();
    scattered = Math::Ray3D(hit.point, reflectedRay-hit.point);
    attenuation = _albedo->get(hit.uPos, hit.vPos, hit.point);
    return true;
}
