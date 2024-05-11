/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Shapes/Plane.hpp"
#include <iostream>

bool RayTracer::Plane::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    float denom = ray.getDirection().dot(_normal);

    if (std::abs(denom) < 1e-6) {
        return false;
    }

    float t = (_position - ray.getOrigin()).dot(_normal) / denom;

    if (t < tmin || t > tmax) {
        return false;
    }

    Math::Vector3D intersection_point = ray.getOrigin() + ray.getDirection() * t;

    // Check if the ray is hitting the plane from the opposite side
    if (denom < 0) {
        hit.normal = -_normal; // Invert the normal
    } else {
        hit.normal = _normal;
    }

    hit.t = t;
    hit.point = intersection_point;
    hit.material = _material;

    return true;
}

RayTracer::Plane::~Plane()
{
}

void RayTracer::Plane::setinfo(const Math::Vector3D &pos, const Math::Vector3D &norm, std::shared_ptr<IMaterial> type)
{
    _position = pos;
    _normal = norm;
    _material = type;
}

extern "C"
{
    RayTracer::Plane *entry_point()
    {
        return new RayTracer::Plane();
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
